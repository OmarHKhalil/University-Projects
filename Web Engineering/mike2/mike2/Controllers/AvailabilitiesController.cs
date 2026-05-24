using System; // Import System for basic types
using System.Linq; // Import for LINQ queries
using System.Threading.Tasks; // Import for async operations
using Microsoft.AspNetCore.Authorization; // Import for authorization
using Microsoft.AspNetCore.Identity; // Import for identity management
using Microsoft.AspNetCore.Mvc; // Import for MVC controller
using Microsoft.EntityFrameworkCore; // Import for EF Core
using mike2.Data; // Import data context
using mike2.Models; // Import models

namespace mike2.Controllers
{
    /// <summary>
    /// Controller for managing availabilities (time slots) for service providers.
    /// Used in /Availabilities pages for providers to manage their schedules.
    /// </summary>
    [Authorize] // Require authentication for all actions
    public class AvailabilitiesController : Controller
    {
        private readonly ApplicationDbContext _context; // Database context DI
        private readonly UserManager<ApplicationUser> _userManager; // User manager DI

        // Constructor with dependency injection
        public AvailabilitiesController(
            ApplicationDbContext context,
            UserManager<ApplicationUser> userManager)
        {
            _context = context; // Assign context
            _userManager = userManager; // Assign user manager
        }

        // Helper: Get the service provider associated with the current user
        private async Task<AppServiceProvider> GetCurrentProviderAsync()
        {
            var userId = _userManager.GetUserId(User); // Get current user ID

            return await _context.ServiceProviders // Find provider for this user
                .Include(p => p.ApplicationUser)
                .FirstOrDefaultAsync(p => p.UserId == userId);
        }

        // GET: Availabilities - Displays availabilities for the current service provider only. Used by Availabilities/Index.cshtml
        public async Task<IActionResult> Index()
        {
            var provider = await GetCurrentProviderAsync(); // Get current provider
            if (provider == null)
            {
                // If no profile, redirect to create one
                return RedirectToAction("Create", "AppServiceProviders");
            }

            var slots = await _context.Availabilities // Get availabilities for this provider
                .Where(a => a.ServiceProviderId == provider.Id)
                .OrderBy(a => a.AvailableDate)
                .ThenBy(a => a.StartTime)
                .ToListAsync();

            return View(slots); // Render Availabilities/Index.cshtml
        }

        // GET: Availabilities/Details/5 - Shows details of an availability slot. Used by Availabilities/Details.cshtml
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null) // Check id
                return NotFound();

            var provider = await GetCurrentProviderAsync(); // Get provider
            if (provider == null)
                return RedirectToAction("Create", "AppServiceProviders");

            var availability = await _context.Availabilities // Find availability for this provider
                .FirstOrDefaultAsync(a => a.Id == id && a.ServiceProviderId == provider.Id);

            if (availability == null)
                return NotFound();

            return View(availability); // Render Availabilities/Details.cshtml
        }

        // GET: Availabilities/Create - Displays create availability form. Used by Availabilities/Create.cshtml
        public async Task<IActionResult> Create()
        {
            var provider = await GetCurrentProviderAsync(); // Get provider
            if (provider == null)
                return RedirectToAction("Create", "AppServiceProviders");

            return View(); // Render create form
        }

        // POST: Availabilities/Create - Creates a new availability slot. Used by Availabilities/Create.cshtml
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> Create(Availability availability)
        {
            var provider = await GetCurrentProviderAsync(); // Get provider
            if (provider == null)
                return RedirectToAction("Create", "AppServiceProviders");

            // Check: End time after start time
            if (availability.EndTime <= availability.StartTime)
            {
                ModelState.AddModelError("", "End time must be after start time.");
            }

            // Check for time overlap with existing availabilities for same provider
            bool hasOverlap = await _context.Availabilities
                .Where(a => a.ServiceProviderId == provider.Id && a.AvailableDate == availability.AvailableDate)
                .AnyAsync(a =>
                    (a.StartTime < availability.EndTime && a.EndTime > availability.StartTime)
                );

            if (hasOverlap)
            {
                ModelState.AddModelError("", "There is a time overlap with an existing availability slot.");
            }

            if (ModelState.IsValid)
            {
                availability.ServiceProviderId = provider.Id; // Set provider
                availability.IsBooked = false; // Always false when creating

                _context.Availabilities.Add(availability); // Add to context
                await _context.SaveChangesAsync(); // Save
                return RedirectToAction(nameof(Index)); // Redirect to list
            }

            return View(availability); // Return with errors
        }

        // GET: Availabilities/Edit/5 - Displays edit availability form. Used by Availabilities/Edit.cshtml
        public async Task<IActionResult> Edit(int? id)
        {
            if (id == null)
                return NotFound();

            var provider = await GetCurrentProviderAsync(); // Get provider
            if (provider == null)
                return RedirectToAction("Create", "AppServiceProviders");

            var availability = await _context.Availabilities // Find availability for this provider
                .FirstOrDefaultAsync(a => a.Id == id && a.ServiceProviderId == provider.Id);

            if (availability == null)
                return NotFound();

            return View(availability); // Render edit form
        }

        // POST: Availabilities/Edit/5 - Updates availability slot. Used by Availabilities/Edit.cshtml
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> Edit(int id, Availability availability)
        {
            if (id != availability.Id) // Validate id
                return NotFound();

            var provider = await GetCurrentProviderAsync(); // Get provider
            if (provider == null)
                return RedirectToAction("Create", "AppServiceProviders");

            if (availability.EndTime <= availability.StartTime) // Time validation
            {
                ModelState.AddModelError("", "End time must be after start time.");
            }

            // Check for overlap with existing availabilities (skip check for the same record being edited)
            bool hasOverlap = await _context.Availabilities
                .Where(a => a.ServiceProviderId == provider.Id &&
                           a.AvailableDate == availability.AvailableDate &&
                           a.Id != id)  // Exclude current record
                .AnyAsync(a =>
                    (a.StartTime < availability.EndTime && a.EndTime > availability.StartTime)
                );

            if (hasOverlap)
            {
                ModelState.AddModelError("", "There is a time overlap with an existing availability slot.");
            }

            if (!ModelState.IsValid)
                return View(availability);

            try
            {
                // Confirm the record belongs to the same provider
                availability.ServiceProviderId = provider.Id;
                _context.Update(availability); // Update
                await _context.SaveChangesAsync(); // Save
            }
            catch (DbUpdateConcurrencyException) // Handle concurrency
            {
                if (!AvailabilityExists(availability.Id))
                    return NotFound();
                else
                    throw; // Re-throw
            }

            return RedirectToAction(nameof(Index)); // Redirect to list
        }

        // GET: Availabilities/Delete/5 - Confirmation for deleting availability. Used by Availabilities/Delete.cshtml
        public async Task<IActionResult> Delete(int? id)
        {
            if (id == null)
                return NotFound();

            var provider = await GetCurrentProviderAsync(); // Get provider
            if (provider == null)
                return RedirectToAction("Create", "AppServiceProviders");

            var availability = await _context.Availabilities // Find availability
                .FirstOrDefaultAsync(a => a.Id == id && a.ServiceProviderId == provider.Id);

            if (availability == null)
                return NotFound();

            return View(availability); // Render delete confirmation
        }

        // POST: Availabilities/Delete/5 - Deletes availability slot. Used by Availabilities/Delete.cshtml
        [HttpPost, ActionName("Delete")]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> DeleteConfirmed(int id)
        {
            TempData["DebugInfo"] = $"Attempting to delete availability ID: {id}"; // Debug info

            var provider = await GetCurrentProviderAsync(); // Get provider
            if (provider == null)
            {
                TempData["ErrorMessage"] = "You must create a service provider profile first";
                return RedirectToAction("Create", "AppServiceProviders");
            }

            var availability = await _context.Availabilities // Find availability
                .FirstOrDefaultAsync(a => a.Id == id && a.ServiceProviderId == provider.Id);

            if (availability == null)
            {
                TempData["ErrorMessage"] = $"Availability not found or does not belong to current provider";
                return RedirectToAction(nameof(Index));
            }

            // Check for associated bookings
            var hasBooking = await _context.Bookings.AnyAsync(b => b.AvailabilityId == id);
            if (availability.IsBooked || hasBooking)
            {
                TempData["ErrorMessage"] = "Cannot delete a booked slot or one with an active booking.";
                return RedirectToAction(nameof(Index));
            }

            try
            {
                _context.Availabilities.Remove(availability); // Remove from context
                await _context.SaveChangesAsync(); // Save changes
                TempData["SuccessMessage"] = "Availability slot deleted successfully.";
            }
            catch (Exception ex)
            {
                TempData["ErrorMessage"] = $"Error occurred during deletion: {ex.Message}";
                TempData["DebugInfo"] += $". Exception: {ex.GetType().Name}";
            }

            return RedirectToAction(nameof(Index)); // Redirect to list
        }

        // Helper method to check if availability exists
        private bool AvailabilityExists(int id)
        {
            return _context.Availabilities.Any(e => e.Id == id); // Check existence
        }
    }
}
