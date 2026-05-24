using Microsoft.AspNetCore.Mvc; // Import for MVC
using Microsoft.AspNetCore.Identity; // Import for user management
using mike2.Models; // Import models

/// <summary>
/// UsersController - Simple controller to list all users.
/// Used in /Users pages, likely for admin/testing.
/// </summary>
public class UsersController : Controller
{
    private readonly UserManager<ApplicationUser> _userManager; // User manager DI

    // Constructor with DI
    public UsersController(UserManager<ApplicationUser> userManager)
    {
        _userManager = userManager; // Assign user manager
    }

    // List all users. Used by Users/Index.cshtml
    public IActionResult Index()
    {
        var users = _userManager.Users.ToList(); // Get all users as list
        return View(users); // Render Users/Index.cshtml
    }
}
