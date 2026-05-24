using System; // Import System for DateTime
using System.Collections.Generic; // Import for generics
using System.Linq; // Import for LINQ
using System.Threading.Tasks; // Import for async
using Microsoft.AspNetCore.Authorization; // Import for [Authorize]
using Microsoft.AspNetCore.Identity; // Import for user management
using Microsoft.AspNetCore.Mvc; // Import for MVC
using Microsoft.AspNetCore.Mvc.Rendering; // Import for SelectList
using Microsoft.EntityFrameworkCore; // Import for EF
using mike2.Data; // Import data context
using mike2.Models; // Import models

namespace mike2.Controllers
{
    /// <summary>
    /// NotificationsController - Manages user notifications (CRUD and mark as read).
    /// Used in /Notifications pages like Index.cshtml for viewing personal notifications.
    /// </summary>
    [Authorize] // Require authentication for all actions
    public class NotificationsController : Controller
    {
        private readonly ApplicationDbContext _context; // Database context DI
        private readonly UserManager<ApplicationUser> _userManager; // User manager DI

        // Constructor with DI
        public NotificationsController(ApplicationDbContext context, UserManager<ApplicationUser> userManager)
        {
            _context = context; // Assign context
            _userManager = userManager; // Assign user manager
        }

        // GET: Notifications - List current user's notifications. Used by Notifications/Index.cshtml
        public async Task<IActionResult> Index()
        {
            var user = await _userManager.GetUserAsync(User); // Get current user
            if (user == null)
            {
                return Challenge(); // Challenge for login
            }

            var notifications = await _context.Notifications // Query user's notifications
                .Include(n => n.Booking) // Include related booking
                .Where(n => n.UserId == user.Id)
                .OrderByDescending(n => n.CreatedAt) // Newest first
                .ToListAsync();

            return View(notifications); // Render Notifications/Index.cshtml
        }

        // GET: Notifications/Details/5 - Show notification details. Used by Notifications/Details.cshtml
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)
            {
                return NotFound();
            }

            var notification = await _context.Notifications // Find notification with related data
                .Include(n => n.Booking)
                .Include(n => n.User)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (notification == null)
            {
                return NotFound();
            }

            return View(notification); // Render Notifications/Details.cshtml
        }



        // POST: Notifications/MarkAsRead/5 - Mark notification as read. Used by Notifications/Index.cshtml (AJAX or form)
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> MarkAsRead(int id)
        {
            var user = await _userManager.GetUserAsync(User); // Get current user
            if (user == null)
            {
                return Challenge();
            }

            var notification = await _context.Notifications.FirstOrDefaultAsync(n => n.Id == id && n.UserId == user.Id); // Find user's notification
            if (notification == null)
            {
                return NotFound();
            }

            notification.IsRead = true; // Mark as read
            await _context.SaveChangesAsync(); // Save

            return RedirectToAction(nameof(Index)); // Redirect to list
        }

        // Helper method to check if notification exists
        private bool NotificationExists(int id)
        {
            return _context.Notifications.Any(e => e.Id == id); // Check existence
        }
    }
}
