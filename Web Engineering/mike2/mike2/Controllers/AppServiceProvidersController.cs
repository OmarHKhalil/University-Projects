using Microsoft.AspNetCore.Authorization; // Import for authorization
using Microsoft.AspNetCore.Identity; // Import for user management
using Microsoft.AspNetCore.Mvc; // Import for MVC actions
using Microsoft.AspNetCore.Mvc.Rendering; // Import for SelectList
using Microsoft.EntityFrameworkCore; // Import for EF Core
using mike2.Data; // Import data context
using mike2.Models; // Import models
using mike2.ViewModel; // Import view models
using System; // Import System for DateTime, etc.
using System.Collections.Generic; // Import for collections
using System.Linq; // Import for LINQ
using System.Threading.Tasks; // Import for async tasks

namespace mike2.Controllers
{
    /// <summary>
    /// Controller for managing App Service Providers (CRUD and profile management).
    /// Used in /AppServiceProviders pages for admin entry, and dashboard/profile for providers.
    /// </summary>
    public class AppServiceProvidersController : Controller
    {
        private readonly ApplicationDbContext _context; // Database context DI
        private readonly UserManager<ApplicationUser> _userManager; // User manager DI

        // Constructor with dependency injection
        public AppServiceProvidersController(
            ApplicationDbContext context,
            UserManager<ApplicationUser> userManager)
        {
            _context = context; // Assign context
            _userManager = userManager; // Assign user manager
        }
        // Authorize only for ServiceProvider role - Dashboard for providers to manage profile. Used by AppServiceProviders/Dashboard.cshtml
        [Authorize(Roles = "ServiceProvider")]
        public async Task<IActionResult> Dashboard()
        {
            // Get current user ID
            var userId = _userManager.GetUserId(User);

            // Find the provider associated with this user, include user details
            var provider = await _context.ServiceProviders
                .Include(p => p.ApplicationUser)
                .FirstOrDefaultAsync(p => p.UserId == userId);

            // If no provider profile, redirect to create one
            if (provider == null)
                return RedirectToAction("Create", "AppServiceProviders");

            // Get services provided by this provider
            var services = await _context.Services
                .Where(s => s.ServiceProviderId == provider.Id)
                .ToListAsync();

            // Get availabilities for this provider
            var availabilities = await _context.Availabilities
                .Where(a => a.ServiceProviderId == provider.Id)
                .ToListAsync();

            // Get new (pending) bookings for this provider
            var newBookings = await _context.Bookings
                .Where(b => b.ServiceProviderId == provider.Id &&
                            b.Status == BookingStatus.Pending)
                .ToListAsync();

            // Get history (non-pending) bookings for this provider
            var historyBookings = await _context.Bookings
                .Where(b => b.ServiceProviderId == provider.Id &&
                            b.Status != BookingStatus.Pending)
                .ToListAsync();

            // Get notifications for this user (provider is also a user)
            var notifications = await _context.Notifications
                .Where(n => n.UserId == userId)                 // Based on relationship in ApplicationDbContext
                .OrderByDescending(n => n.CreatedAt)            // Assuming CreatedAt field exists
                .ToListAsync();

            // Count unread notifications (assuming IsRead bool field)
            var unreadCount = notifications.Count(n => !n.IsRead);

            // Create view model with all data
            var vm = new ProviderDashboardViewModel
            {
                Provider = provider,
                Services = services,
                Availabilities = availabilities,
                NewBookings = newBookings,
                HistoryBookings = historyBookings,
                Notifications = notifications,
                UnreadNotificationsCount = unreadCount
            };

            return View(vm); // Render AppServiceProviders/Dashboard.cshtml
        }


        // GET: AppServiceProviders - Lists all service providers. Used by AppServiceProviders/Index.cshtml
        public async Task<IActionResult> Index()
        {
            var applicationDbContext = _context.ServiceProviders.Include(a => a.ApplicationUser); // Query providers with user details
            return View(await applicationDbContext.ToListAsync()); // Render AppServiceProviders/Index.cshtml
        }

        // GET: AppServiceProviders/Details/5 - Shows details of a service provider. Used by AppServiceProviders/Details.cshtml
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null) // Check if id is provided
            {
                return NotFound();
            }

            var appServiceProvider = await _context.ServiceProviders // Find provider with user details
                .Include(a => a.ApplicationUser)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (appServiceProvider == null)
            {
                return NotFound();
            }

            return View(appServiceProvider); // Render AppServiceProviders/Details.cshtml
        }







        // GET: AppServiceProviders/EditProfile - For service providers to edit their profile. Used by AppServiceProviders/EditProfile.cshtml
        public async Task<IActionResult> EditProfile()
        {
            // Get current user ID
            var userId = _userManager.GetUserId(User);
            if (userId == null)
                return Challenge(); // Challenge for login if not authenticated

            // Get provider record for this user
            var provider = await _context.ServiceProviders
                .FirstOrDefaultAsync(p => p.UserId == userId);

            if (provider == null)
                return NotFound();

            // Create view model from provider data
            var vm = new ProviderProfileEditViewModel
            {
                Experience = provider.Experience,
                Specializations = provider.Specializations,
                CoveredAreas = provider.CoveredAreas
            };

            return View(vm); // Render edit profile form
        }

        // POST: AppServiceProviders/EditProfile - Updates provider profile. Used by AppServiceProviders/EditProfile.cshtml
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> EditProfile(ProviderProfileEditViewModel model)
        {
            if (!ModelState.IsValid) // Validate model
                return View(model);

            // Get current user
            var userId = _userManager.GetUserId(User);
            if (userId == null)
                return Challenge();

            // Find provider
            var provider = await _context.ServiceProviders
                .FirstOrDefaultAsync(p => p.UserId == userId);

            if (provider == null)
                return NotFound();

            // Update profile data
            provider.Experience = model.Experience;
            provider.Specializations = model.Specializations;
            provider.CoveredAreas = model.CoveredAreas;

            await _context.SaveChangesAsync(); // Save changes

            TempData["ProfileUpdated"] = "Profile updated successfully."; // Success message

            return RedirectToAction(nameof(EditProfile)); // Redirect back to form
        }

        // Helper method to check if provider exists
        private bool AppServiceProviderExists(int id)
        {
            return _context.ServiceProviders.Any(e => e.Id == id); // Query existence
        }
    }
}
