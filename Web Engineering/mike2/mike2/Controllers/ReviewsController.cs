using System; // Import System for DateTime, etc.
using System.Collections.Generic; // Import for collections
using System.Linq; // Import for LINQ
using System.Threading.Tasks; // Import for async
using Microsoft.AspNetCore.Mvc; // Import for MVC
using Microsoft.AspNetCore.Mvc.Rendering; // Import for SelectList
using Microsoft.EntityFrameworkCore; // Import for EF Core
using mike2.Data; // Import data context
using mike2.Models; // Import models

namespace mike2.Controllers
{
    /// <summary>
    /// ReviewsController - Manages customer reviews for service providers (CRUD).
    /// Used in /Reviews pages for admin review management.
    /// </summary>
    public class ReviewsController : Controller
    {
        private readonly ApplicationDbContext _context; // Database context DI

        // Constructor with DI
        public ReviewsController(ApplicationDbContext context)
        {
            _context = context; // Assign context
        }

        // GET: Reviews - List all reviews. Used by Reviews/Index.cshtml
        public async Task<IActionResult> Index()
        {
            var applicationDbContext = _context.Reviews.Include(r => r.Booking).Include(r => r.Reviewer).Include(r => r.ServiceProvider); // Query reviews with relations
            return View(await applicationDbContext.ToListAsync()); // Render Reviews/Index.cshtml
        }

        // GET: Reviews/Details/5 - Show review details. Used by Reviews/Details.cshtml
        // NOTE: For admin monitoring - allows viewing individual review details if needed
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null) // Check id
            {
                return NotFound();
            }

            var review = await _context.Reviews // Find review with relations
                .Include(r => r.Booking)
                .Include(r => r.Reviewer)
                .Include(r => r.ServiceProvider)
                .FirstOrDefaultAsync(m => m.Id == id);
            if (review == null)
            {
                return NotFound();
            }

            return View(review); // Render Reviews/Details.cshtml
        }







        // Helper method to check if review exists
        private bool ReviewExists(int id)
        {
            return _context.Reviews.Any(e => e.Id == id); // Check existence
        }
    }
}
