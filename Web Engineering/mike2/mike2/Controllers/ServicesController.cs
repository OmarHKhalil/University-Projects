using System.Linq; // Import for LINQ
using System.Threading.Tasks; // Import for async
using Microsoft.AspNetCore.Authorization; // Import for authorization
using Microsoft.AspNetCore.Identity; // Import for user management
using Microsoft.AspNetCore.Mvc; // Import for MVC
using Microsoft.EntityFrameworkCore; // Import for EF Core
using mike2.Data; // Import data context
using mike2.Models; // Import models

namespace mike2.Controllers
{
    /// <summary>
    /// ServicesController - Manages services for authenticated service providers (only their own).
    /// Used in /Services pages for providers to manage offerings.
    /// </summary>
    [Authorize(Roles = "ServiceProvider")] // Require ServiceProvider role
    public class ServicesController : Controller
    {
        private readonly ApplicationDbContext _context; // Database context DI
        private readonly UserManager<ApplicationUser> _userManager; // User manager DI

        // Constructor with DI
        public ServicesController(ApplicationDbContext context, UserManager<ApplicationUser> userManager)
        {
            _context = context; // Assign context
            _userManager = userManager; // Assign user manager
        }

        // Display provider's services
        public async Task<IActionResult> Index()
        {
            var user = await _userManager.GetUserAsync(User); // Get current user

            var provider = await _context.ServiceProviders // Find provider for user
                .FirstOrDefaultAsync(p => p.UserId == user.Id);

            if (provider == null)
                return NotFound();

            var services = await _context.Services // Get provider's services
                .Where(s => s.ServiceProviderId == provider.Id)
                .ToListAsync();

            return View(services); // Render Services/Index.cshtml
        }

        // Service details (owner only)
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null) return NotFound();

            var service = await _context.Services // Find service with provider
                .Include(s => s.ServiceProvider)
                .FirstOrDefaultAsync(m => m.Id == id);

            if (service == null) return NotFound();

            // Prevent viewing non-owned service
            var user = await _userManager.GetUserAsync(User);
            var provider = await _context.ServiceProviders.FirstOrDefaultAsync(p => p.UserId == user.Id);

            if (service.ServiceProviderId != provider.Id)
                return Forbid();

            return View(service); // Render Services/Details.cshtml
        }

        // Add new service
        public IActionResult Create()
        {
            return View(); // Render create form
        }

        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> Create(Service service)
        {
            var user = await _userManager.GetUserAsync(User); // Get user

            var provider = await _context.ServiceProviders // Find provider
                .FirstOrDefaultAsync(p => p.UserId == user.Id);

            if (provider == null)
                return NotFound();

            // Link service to current provider
            service.ServiceProviderId = provider.Id;

            // Remove ServiceProviderId from ModelState if hidden field exists
            ModelState.Remove("ServiceProviderId");

            if (ModelState.IsValid) // Check validity
            {
                _context.Add(service); // Add service
                await _context.SaveChangesAsync(); // Save
                return RedirectToAction(nameof(Index)); // Redirect to list
            }

            return View(service); // Return with errors
        }

        // Edit service
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null) return NotFound();

            var service = await _context.Services.FindAsync(id); // Find service
            if (service == null) return NotFound();

            var user = await _userManager.GetUserAsync(User);
            var provider = await _context.ServiceProviders.FirstOrDefaultAsync(p => p.UserId == user.Id);

            // Prevent editing non-owned service
            if (service.ServiceProviderId != provider.Id)
                return Forbid();

            return View(service); // Render edit form
        }

        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> Edit(int id, Service service)
        {
            if (id != service.Id) return NotFound();

            var existing = await _context.Services.FindAsync(id); // Find existing
            if (existing == null) return NotFound();

            var user = await _userManager.GetUserAsync(User);
            var provider = await _context.ServiceProviders.FirstOrDefaultAsync(p => p.UserId == user.Id);

            if (existing.ServiceProviderId != provider.Id)
                return Forbid();

            // Update only allowed fields
            existing.Name = service.Name;
            existing.Description = service.Description;
            existing.Category = service.Category;
            existing.BasePrice = service.BasePrice;

            await _context.SaveChangesAsync(); // Save changes

            return RedirectToAction(nameof(Index)); // Redirect to list
        }

        // Delete service
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null) return NotFound();

            var service = await _context.Services.FindAsync(id); // Find service
            if (service == null) return NotFound();

            var user = await _userManager.GetUserAsync(User);
            var provider = await _context.ServiceProviders.FirstOrDefaultAsync(p => p.UserId == user.Id);

            if (service.ServiceProviderId != provider.Id)
                return Forbid();

            return View(service); // Render delete confirmation
        }

        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            var service = await _context.Services.FindAsync(id); // Find service

            if (service != null)
            {
                var user = await _userManager.GetUserAsync(User);
                var provider = await _context.ServiceProviders.FirstOrDefaultAsync(p => p.UserId == user.Id);

                if (service.ServiceProviderId != provider.Id)
                    return Forbid();

                _context.Services.Remove(service); // Remove service
                await _context.SaveChangesAsync(); // Save changes
            }

            return RedirectToAction(nameof(Index)); // Redirect to list
        }

        // Helper method to check if service exists
        private bool ServiceExists(int id)
        {
            return _context.Services.Any(e => e.Id == id); // Check existence
        }
    }
}
