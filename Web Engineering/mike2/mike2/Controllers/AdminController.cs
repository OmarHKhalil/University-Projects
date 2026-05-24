using System; // Import System namespace for basic types like DateTime
using System.Linq; // Import LINQ for querying collections
using System.Threading.Tasks; // Import Tasks for asynchronous operations
using Microsoft.AspNetCore.Authorization; // Import for authorization attributes
using Microsoft.AspNetCore.Identity; // Import Identity for user management
using Microsoft.AspNetCore.Mvc; // Import MVC for controller functionality
using Microsoft.EntityFrameworkCore; // Import EF Core for database operations
using mike2.Data; // Import data access layer
using mike2.Models; // Import domain models

namespace mike2.Controllers
{
    /// <summary>
    /// Admin dashboard with user management, reviews, and reports. This controller is for administrative tasks.
    /// Used in /Admin pages.
    /// </summary>
    [Authorize(Roles = "Admin")] // Restrict access to users with Admin role
    public class AdminController : Controller
    {
        private readonly ApplicationDbContext _context; // Database context dependency injected
        private readonly UserManager<ApplicationUser> _userManager; // User management service
        private readonly RoleManager<IdentityRole> _roleManager; // Role management service

        // Constructor with dependency injection
        public AdminController(ApplicationDbContext context, UserManager<ApplicationUser> userManager, RoleManager<IdentityRole> roleManager)
        {
            _context = context; // Assign context
            _userManager = userManager; // Assign user manager
            _roleManager = roleManager; // Assign role manager
        }

        // GET: /Admin - Displays admin dashboard with statistics. Used by Admin/Index.cshtml
        public async Task<IActionResult> Index()
        {
            var today = DateTime.Today; // Get today's date
            var monthStart = new DateTime(today.Year, today.Month, 1); // Get first day of current month

            // Count bookings for today
            var todayBookings = await _context.Bookings
                .CountAsync(b => b.BookingDate.Date == today);

            // Count bookings for current month
            var monthBookings = await _context.Bookings
                .CountAsync(b => b.BookingDate >= monthStart && b.BookingDate < monthStart.AddMonths(1));

            // Count total users
            var totalUsers = await _userManager.Users.CountAsync();
            // Count active users
            var activeUsers = await _userManager.Users.CountAsync(u => u.IsActive);

            // Count total reviews
            var totalReviews = await _context.Reviews.CountAsync();
            // Count visible reviews
            var visibleReviews = await _context.Reviews.CountAsync(r => r.IsVisible);

            // Create view model with statistics
            var vm = new AdminDashboardViewModel
            {
                TodayBookings = todayBookings,
                MonthBookings = monthBookings,
                TotalUsers = totalUsers,
                ActiveUsers = activeUsers,
                TotalReviews = totalReviews,
                VisibleReviews = visibleReviews
            };

            return View(vm); // Render Admin/Index.cshtml with view model
        }

        // GET: /Admin/Users - Lists all users. Used by Admin/Users.cshtml
        public IActionResult Users()
        {
            var users = _userManager.Users.ToList(); // Get all users as list
            return View(users); // Render Admin/Users.cshtml with users
        }

        // GET: /Admin/CreateUser - Displays create user form. Used by Admin/CreateUser.cshtml
        public IActionResult CreateUser()
        {
            ViewBag.Roles = Enum.GetNames(typeof(UserRole)); // Pass role names to view
            return View(new AdminUserEditViewModel { IsActive = true }); // Render create form with default active user
        }

        // POST: /Admin/CreateUser - Creates a new user. Used by Admin/CreateUser.cshtml
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> CreateUser(AdminUserEditViewModel model)
        {
            ViewBag.Roles = Enum.GetNames(typeof(UserRole)); // Pass roles for validation errors

            if (!ModelState.IsValid) // Check if model is valid
            {
                return View(model); // Return with errors if invalid
            }

            if (string.IsNullOrWhiteSpace(model.Password)) // Check if password provided
            {
                ModelState.AddModelError(nameof(model.Password), "Password is required.");
                return View(model);
            }

            var existing = await _userManager.FindByEmailAsync(model.Email); // Check if email exists
            if (existing != null)
            {
                ModelState.AddModelError(nameof(model.Email), "Email is already in use.");
                return View(model);
            }

            // Create new user object
            var user = new ApplicationUser
            {
                UserName = model.Email,
                Email = model.Email,
                EmailConfirmed = true, // Auto-confirm for admin created
                FullName = model.FullName ?? string.Empty,
                Location = model.Location ?? string.Empty,
                Role = model.Role,
                IsActive = model.IsActive
            };

            var result = await _userManager.CreateAsync(user, model.Password); // Create user with password
            if (!result.Succeeded)
            {
                foreach (var error in result.Errors)
                {
                    ModelState.AddModelError(string.Empty, error.Description);
                }
                return View(model);
            }

            // Add to ASP.NET Identity role - Create role if not exists
            var roleName = model.Role.ToString();
            if (!await _roleManager.RoleExistsAsync(roleName))
            {
                await _roleManager.CreateAsync(new IdentityRole(roleName));
            }
            await _userManager.AddToRoleAsync(user, roleName);

            return RedirectToAction(nameof(Users)); // Redirect to users list
        }

        // GET: /Admin/EditUser/5 - Displays edit user form. Used by Admin/EditUser.cshtml
        public async Task<IActionResult> EditUser(string id)
        {
            if (string.IsNullOrEmpty(id)) // Check if id is provided
            {
                return NotFound();
            }

            var user = await _userManager.FindByIdAsync(id); // Find user by id
            if (user == null)
            {
                return NotFound();
            }

            // Create view model from user data
            var vm = new AdminUserEditViewModel
            {
                Id = user.Id,
                FullName = user.FullName,
                Email = user.Email,
                Location = user.Location,
                Role = user.Role,
                IsActive = user.IsActive
            };

            ViewBag.Roles = Enum.GetNames(typeof(UserRole)); // Pass roles to view
            return View(vm); // Render Admin/EditUser.cshtml
        }

        // POST: /Admin/EditUser/5 - Updates user details. Used by Admin/EditUser.cshtml
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> EditUser(string id, AdminUserEditViewModel model)
        {
            if (id != model.Id) // Validate id match
            {
                return NotFound();
            }

            ViewBag.Roles = Enum.GetNames(typeof(UserRole)); // Pass roles for validation

            if (!ModelState.IsValid) // Check model validity
            {
                return View(model); // Return with errors
            }

            var user = await _userManager.FindByIdAsync(id); // Find user
            if (user == null)
            {
                return NotFound();
            }

            // Update basic user fields
            user.FullName = model.FullName ?? string.Empty;
            user.Email = model.Email;
            user.UserName = model.Email;
            user.Location = model.Location ?? string.Empty;
            user.IsActive = model.IsActive;
            user.Role = model.Role;

            var result = await _userManager.UpdateAsync(user); // Update user
            if (!result.Succeeded)
            {
                foreach (var error in result.Errors)
                {
                    ModelState.AddModelError(string.Empty, error.Description);
                }
                return View(model);
            }

            // Sync ASP.NET Identity Role - Remove all roles first
            var allRoles = Enum.GetNames(typeof(UserRole));
            foreach (var r in allRoles)
            {
                if (await _userManager.IsInRoleAsync(user, r))
                {
                    await _userManager.RemoveFromRoleAsync(user, r);
                }
            }

            // Add new role
            var newRoleName = model.Role.ToString();
            if (!await _roleManager.RoleExistsAsync(newRoleName))
            {
                await _roleManager.CreateAsync(new IdentityRole(newRoleName));
            }
            await _userManager.AddToRoleAsync(user, newRoleName);

            return RedirectToAction(nameof(Users)); // Redirect to users list
        }

        // POST: /Admin/ToggleUserActive/5 - Toggles user active status. Used by Admin/Users.cshtml (AJAX call)
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> ToggleUserActive(string id)
        {
            if (string.IsNullOrEmpty(id)) // Check id
            {
                return NotFound();
            }

            var user = await _userManager.Users.FirstOrDefaultAsync(u => u.Id == id); // Find user
            if (user == null)
            {
                return NotFound();
            }

            user.IsActive = !user.IsActive; // Toggle active status
            await _userManager.UpdateAsync(user); // Update user

            return RedirectToAction(nameof(Users)); // Redirect to users list
        }

        // GET: /Admin/Reviews - Lists all reviews. Used by Admin/Reviews.cshtml
        public async Task<IActionResult> Reviews()
        {
            var reviews = await _context.Reviews // Query reviews with includes
                .Include(r => r.Reviewer)
                .Include(r => r.ServiceProvider)
                .OrderByDescending(r => r.CreatedAt) // Newest first
                .ToListAsync();

            return View(reviews); // Render Admin/Reviews.cshtml
        }

        // POST: /Admin/ToggleReviewVisibility/5 - Toggles review visibility. Used by Admin/Reviews.cshtml
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> ToggleReviewVisibility(int id)
        {
            var review = await _context.Reviews.FindAsync(id); // Find review
            if (review == null)
            {
                return NotFound();
            }

            review.IsVisible = !review.IsVisible; // Toggle visibility
            await _context.SaveChangesAsync(); // Save changes

            return RedirectToAction(nameof(Reviews)); // Redirect to reviews list
        }

        // GET: /Admin/Services - Lists all services. Used by Admin/Services.cshtml
        public async Task<IActionResult> Services()
        {
            var services = await _context.Services // Query services with provider info
                .Include(s => s.ServiceProvider)
                    .ThenInclude(sp => sp.ApplicationUser)
                .OrderBy(s => s.Category)
                .ThenBy(s => s.Name) // Order by category then name
                .ToListAsync();

            return View(services); // Render Admin/Services.cshtml
        }

        // GET: /Admin/EditService/5 - Displays edit service form. Used by Admin/EditService.cshtml
        public async Task<IActionResult> EditService(int? id)
        {
            if (id == null) // Check if id provided
            {
                return NotFound();
            }

            var service = await _context.Services // Find service with provider
                .Include(s => s.ServiceProvider)
                    .ThenInclude(sp => sp.ApplicationUser)
                .FirstOrDefaultAsync(s => s.Id == id);

            if (service == null)
            {
                return NotFound();
            }

            return View(service); // Render Admin/EditService.cshtml
        }

        // POST: /Admin/EditService/5 - Updates service details. Used by Admin/EditService.cshtml
        [HttpPost]
        [ValidateAntiForgeryToken] // CSRF protection
        public async Task<IActionResult> EditService(int id, [Bind("Id,Name,Category,Description,BasePrice")] Service edited)
        {
            if (id != edited.Id) // Validate id match
            {
                return NotFound();
            }

            if (!ModelState.IsValid) // Check model validity
            {
                return View(edited); // Return with errors
            }

            var service = await _context.Services.FindAsync(id); // Find existing service
            if (service == null)
            {
                return NotFound();
            }

            // Update only allowed fields (Name, Category, Description, BasePrice for basic service and categories)
            service.Name = edited.Name;
            service.Category = edited.Category;
            service.Description = edited.Description;
            service.BasePrice = edited.BasePrice;

            await _context.SaveChangesAsync(); // Save changes

            return RedirectToAction(nameof(Services)); // Redirect to services list
        }

        // GET: /Admin/Reports - Displays reports with statistics. Used by Admin/Reports.cshtml
        public async Task<IActionResult> Reports()
        {
            var today = DateTime.Today; // Today's date
            var monthStart = new DateTime(today.Year, today.Month, 1); // Start of current month

            // Calculate today's bookings count
            var todayBookings = await _context.Bookings
                .CountAsync(b => b.BookingDate.Date == today);

            // Calculate current month bookings count
            var monthBookings = await _context.Bookings
                .CountAsync(b => b.BookingDate >= monthStart && b.BookingDate < monthStart.AddMonths(1));

            // User counts
            var totalUsers = await _userManager.Users.CountAsync();
            var activeUsers = await _userManager.Users.CountAsync(u => u.IsActive);

            // Review counts
            var totalReviews = await _context.Reviews.CountAsync();
            var visibleReviews = await _context.Reviews.CountAsync(r => r.IsVisible);

            // Create reports view model
            var vm = new AdminReportsViewModel
            {
                TodayBookings = todayBookings,
                MonthBookings = monthBookings,
                TotalUsers = totalUsers,
                ActiveUsers = activeUsers,
                TotalReviews = totalReviews,
                VisibleReviews = visibleReviews
            };

            return View(vm); // Render Admin/Reports.cshtml
        }
    }

    public class AdminDashboardViewModel
    {
        public int TodayBookings { get; set; }
        public int MonthBookings { get; set; }
        public int TotalUsers { get; set; }
        public int ActiveUsers { get; set; }
        public int TotalReviews { get; set; }
        public int VisibleReviews { get; set; }
    }

    public class AdminReportsViewModel
    {
        public int TodayBookings { get; set; }
        public int MonthBookings { get; set; }
        public int TotalUsers { get; set; }
        public int ActiveUsers { get; set; }
        public int TotalReviews { get; set; }
        public int VisibleReviews { get; set; }
    }

    public class AdminUserEditViewModel
    {
        public string? Id { get; set; }
        public string? FullName { get; set; }
        public string Email { get; set; } = string.Empty;
        public string? Location { get; set; }
        public UserRole Role { get; set; } = UserRole.Customer;
        public bool IsActive { get; set; } = true;

        // For create only (optional on edit)
        public string? Password { get; set; }
    }
}
