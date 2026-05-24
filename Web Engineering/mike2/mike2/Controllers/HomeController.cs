using System.Diagnostics; // Import for DiagnosticSource, Activity traces
using Microsoft.AspNetCore.Mvc; // Import for MVC controller base and actions
using mike2.Models; // Import domain models including ErrorViewModel

namespace mike2.Controllers
{
    /// <summary>
    /// HomeController - Handless general pages like home, privacy, error.
    /// Used in /Home pages like Index.cshtml, Privacy.cshtml, Error.cshtml.
    /// </summary>
    public class HomeController : Controller
    {
        // GET: /Home - Default home page. Used by Home/Index.cshtml
        public IActionResult Index()
        {
            return View(); // Render Home/Index.cshtml
        }

        // GET: /Home/Privacy - Privacy policy page. Used by Home/Privacy.cshtml
        public IActionResult Privacy()
        {
            return View(); // Render Home/Privacy.cshtml
        }

        // [AllowAnonymous] GET: /Home/Error - Error page with no caching to prevent stale errors. Used by Home/Error.cshtml
        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)] // Prevent caching of error page
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier }); // Render Home/Error.cshtml with error model
        }
    }
}
