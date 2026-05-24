/**
 * BookingsController - Comprehensive booking management system
 *
 * This controller manages the complete booking lifecycle between customers and service providers:
 * - Customers can browse services and submit booking requests
 * - Service providers can accept/reject booking requests and mark services as completed
 * - Implements notification system for all parties
 * - Handles booking status transitions: Pending -> Accepted/Rejected -> Completed
 * - Supports customer reviews for completed bookings
 * - Includes cancellation policy (12 hours notice required)
 *
 * Used throughout the application on pages like:
 * - /Bookings/CreateForCustomer.cshtml (main booking page for customers)
 * - /Bookings/MyBookings.cshtml (customer's booking history)
 * - /Bookings/ProviderNewBookings.cshtml (provider's pending requests)
 * - /Bookings/ProviderBookingHistory.cshtml (provider's booking history)
 * - /Bookings/CreateReview.cshtml (customer review submission)
 *
 * Business Flow:
 * Customer -> [Browse Services] -> [Select Availability] -> [Submit Booking Request]
 *                ↓
 * Provider -> [Receive Notification] -> [Accept/Reject] -> [Complete Service]
 *                ↓
 * Customer -> [Review Completed Service]
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Authorization;  // Import for authorization attributes
using Microsoft.AspNetCore.Identity;      // Import for user authentication
using Microsoft.AspNetCore.Mvc;          // Import for MVC controller actions
using Microsoft.AspNetCore.Mvc.Rendering; // Import for SelectList dropdowns
using Microsoft.EntityFrameworkCore;     // Import for EF Core database queries
using mike2.Data;                        // Import data context
using mike2.Models;                      // Import domain models
using mike2.ViewModels;                  // Import view models

namespace mike2.Controllers
{
    /// <summary>
    /// Bookings Controller - Manages the complete booking flow
    /// Connects customers and service providers
    /// </summary>
    public class BookingsController : Controller
    {
        private readonly ApplicationDbContext _context;
        private readonly UserManager<ApplicationUser> _userManager;

    public BookingsController(ApplicationDbContext context, UserManager<ApplicationUser> userManager)
    {
        _context = context;          // Inject database context for DB operations
        _userManager = userManager;  // Inject user manager for authentication operations
    }

        // GET: Bookings/Index - Shows all bookings for admins, used by Index.cshtml
        // CALLABLE BY: Admin only - Full system overview of all bookings
        public async Task<IActionResult> Index()
        {
            // Fetch all bookings from database with related entities loaded
            var applicationDbContext = _context.Bookings                           // Access Bookings table
                .Include(b => b.Availability)                                  // Load related Availability details
                .Include(b => b.Customer)                                     // Loadrelated Customer details
                .Include(b => b.Service)                                      // Load related Service details
                .Include(b => b.ServiceProvider);                            // Load related ServiceProvider details

            // Convert to list and return to view for rendering
            return View(await applicationDbContext.ToListAsync());           // Execute query and return ViewResult
        }

        // GET: Bookings/Details/5 - Shows booking details for admin monitoring, used by Details.cshtml
        // CALLABLE BY: Admin only - Detailed view of specific booking for administrative review
        public async Task<IActionResult> Details(int? id)
        {
            if (id == null)                                           // Check if id parameter is null
            {
                return NotFound();                                   // Return 404 Not Found result
            }

            var booking = await _context.Bookings                    // Query Bookings table
                .Include(b => b.Availability)                        // Load related Availability data
                .Include(b => b.Customer)                            // Load related Customer data
                .Include(b => b.Service)                             // Load related Service data
                .Include(b => b.ServiceProvider)                     // Load related ServiceProvider data
                .FirstOrDefaultAsync(m => m.Id == id);              // Get first booking where Id matches parameter
            if (booking == null)                                     // Check if booking was found
            {
                return NotFound();                                   // Return 404 if booking doesn't exist
            }

            return View(booking);                                    // Render Details view with booking model
        }

        // ---------- Customer Flow: Create Booking ----------

        // GET: /Bookings/CreateForCustomer - Shows service selection and booking page, used by CreateForCustomer.cshtml
        // CALLABLE BY: Customer only - Service browsing and booking creation interface
        [Authorize(Roles = "Customer")] // Only customers can access this action - restrict to Customers role
        public async Task<IActionResult> CreateForCustomer(string? category = null, string? region = null, int? priceSort = null, int? serviceId = null) // Optional parameters: category filter, region filter, price sort, specific service ID
        {
            // Retrieve the currently logged-in user from ASP.NET Identity
            var user = await _userManager.GetUserAsync(User); // Get ApplicationUser object from current User principal
            if (user == null) // If no user found (not authenticated)
            {
                return Challenge(); // Redirect to login page with challenge response
            }

            // Build initial query for Services table with related Provider data
            var servicesQuery = _context.Services           // Access Services table
                .Include(s => s.ServiceProvider)            // Eager load ServiceProvider relation
                    .ThenInclude(sp => sp.ApplicationUser)  // Then load ApplicationUser for provider details
                .AsQueryable();                             // Convert to IQueryable for additional filtering

            // Apply category filter if category parameter provided
            if (!string.IsNullOrWhiteSpace(category))       // Check if category string is not null/empty/whitespace
            {
                servicesQuery = servicesQuery.Where(s => s.Category == category); // Filter services by category match
            }

            // Apply region filter if region parameter provided
            if (!string.IsNullOrWhiteSpace(region))         // Check if region string is not null/empty/whitespace
            {
                servicesQuery = servicesQuery.Where(s => s.ServiceProvider.CoveredAreas.Contains(region)); // Filter services by provider's covered areas
            }

            // Apply price sorting
            IOrderedQueryable<Service> orderedServices;
            if (priceSort.HasValue && priceSort.Value == 1) // Ascending
            {
                orderedServices = servicesQuery.OrderBy(s => s.BasePrice).ThenBy(s => s.Category).ThenBy(s => s.Name);
            }
            else if (priceSort.HasValue && priceSort.Value == 2) // Descending
            {
                orderedServices = servicesQuery.OrderByDescending(s => s.BasePrice).ThenBy(s => s.Category).ThenBy(s => s.Name);
            }
            else // Default sorting by category then name
            {
                orderedServices = servicesQuery.OrderBy(s => s.Category).ThenBy(s => s.Name);
            }

            // Execute services query
            var services = await orderedServices.ToListAsync(); // Materialize results into List<Service>

            // Query distinct categories from Services table for dropdown filter
            var distinctCategories = await _context.Services  // New query on Services table
                .Select(s => s.Category)                     // Project to select only Category property
                .Distinct()                                  // Remove duplicate categories
                .OrderBy(c => c)                             // Sort categories alphabetically
                .ToListAsync();                              // Get List<string> of categories

            // Query distinct regions from ServiceProviders table for dropdown filter
            var distinctRegions = await _context.ServiceProviders  // New query on ServiceProviders table
                .Where(sp => sp.CoveredAreas != null && sp.CoveredAreas != "") // Filter non-empty
                .Select(sp => sp.CoveredAreas)                    // Project to select only CoveredAreas property
                .Distinct()                                       // Remove duplicate regions
                .OrderBy(r => r)                                 // Sort regions alphabetically
                .ToListAsync();                                  // Get List<string> of regions

            // Create empty list to store provider groups with their services
            var providersWithServices = new List<ProviderWithServicesViewModel>(); // Initialize view model collection

            // Group services by ServiceProviderId to organize by provider
            var providerGroups = services.GroupBy(s => s.ServiceProviderId); // LINQ GroupBy operation

            // Iterate through each provider's service group
            foreach (var providerGroup in providerGroups)     // Loop through grouped providers
            {
                var provider = providerGroup.First().ServiceProvider!; // Get provider entity from first service (use ! because include ensures it's loaded)
                var providerServices = providerGroup.ToList();         // Convert group to List<Service>

                // Fetch latest 3 visible reviews for this provider
                var reviews = await _context.Reviews            // Query Reviews table
                    .Include(r => r.Booking)                    // Load related Booking
                    .ThenInclude(b => b.Customer)               // Then load Customer from Booking
                    .Where(r => r.ServiceProviderId == provider.Id && r.IsVisible) // Filter by provider and visibility
                    .OrderByDescending(r => r.CreatedAt)       // Sort by creation date descending
                    .Take(3)                                    // Limit to 3 most recent reviews
                    .ToListAsync();                             // Execute query

                // Calculate total reviews count for statistics
                var totalReviews = await _context.Reviews.CountAsync(r => r.ServiceProviderId == provider.Id && r.IsVisible); // Count visible reviews
                var averageRating = totalReviews > 0 ? (float)reviews.Average(r => r.Rating) : 0f; // Calculate average rating or 0

                // Create empty list for service-with-availability objects
                var servicesWithAvailabilities = new List<ServiceWithAvailabilitiesViewModel>(); // Initialize collection

                // Loop through each service this provider offers
                foreach (var service in providerServices)       // Iterate provider's services
                {
                    // Query available time slots for this service's provider
                    var availabilities = await _context.Availabilities // Query Availabilities table
                        .Where(a => a.ServiceProviderId == provider.Id && !a.IsBooked && a.AvailableDate >= DateTime.Today) // Filter: provider, not booked, future dates
                        .OrderBy(a => a.AvailableDate)           // Sort by date ascending
                        .ThenBy(a => a.StartTime)                // Then by start time ascending
                        .Take(5)                                 // Limit to 5 slots per service
                        .ToListAsync();                          // Execute query

                    // Create view model for service with its available slots
                    servicesWithAvailabilities.Add(new ServiceWithAvailabilitiesViewModel // Instantiate view model
                    {
                        ServiceId = service.Id,                  // Set service identifier
                        ServiceName = service.Name,              // Set service display name
                        Category = service.Category,             // Set service category
                        Description = service.Description,       // Set service description
                        Region = service.ServiceProvider.CoveredAreas, // Set service region
                        BasePrice = service.BasePrice,           // Set service base price
                        AvailableSlots = availabilities          // Assign available time slots list
                    });
                }

                // Add complete provider information to main view model list
                providersWithServices.Add(new ProviderWithServicesViewModel // Create provider view model
                {
                    Provider = provider,                        // Assign provider entity
                    Services = servicesWithAvailabilities,      // Assign services with availability
                    RecentReviews = reviews,                    // Assign recent reviews
                    AverageRating = averageRating,              // Assign calculated rating
                    TotalReviewCount = totalReviews             // Assign total review count
                });
            }

            // Build final view model with all collected data
            var vm = new CreateBookingViewModel               // Instantiate view model object
            {
                CategoryFilter = category,                     // Set current category filter value
                RegionFilter = region,                         // Set current region filter value
                PriceSort = priceSort,                         // Set current price sort value
                Categories = distinctCategories.Select(c => new SelectListItem // Build categories dropdown list
                {
                    Value = c,                                 // Category value
                    Text = c,                                  // Category display text
                    Selected = c == category                   // Mark selected if matches current filter
                }).ToList(),
                Regions = distinctRegions.Select(r => new SelectListItem // Build regions dropdown list
                {
                    Value = r,                                 // Region value
                    Text = r,                                  // Region display text
                    Selected = r == region                     // Mark selected if matches current filter
                }).ToList(),
                Services = services.Select(s => new SelectListItem // Build services dropdown list
                {
                    Value = s.Id.ToString(),                   // Service ID as value
                    Text = $"{s.Name} ({s.Category}) - {s.ServiceProvider?.ApplicationUser?.FullName}" // Formatted display text
                }).ToList(),
                ProvidersWithServices = providersWithServices // Assign providers data
            };

            // If specific service ID passed in URL, populate detailed dropdowns
            if (serviceId.HasValue && serviceId.Value > 0)      // Check if serviceId parameter valid
            {
                vm.ServiceId = serviceId.Value;                // Set the selected service ID
                await PopulateCreateLists(vm);                 // Call helper to populate time slots
            }

            return View(vm);                                   // Return view with populated view model
        }

        // POST: Bookings/CreateForCustomer - Processes booking submission, creates booking & notifications, used by CreateForCustomer.cshtml
        // CALLABLE BY: Customer only - Process and validate booking creation request
        [Authorize(Roles = "Customer")] // Restricts access to users with "Customer" role only
        [HttpPost]                    // Handles HTTP POST requests
        [ValidateAntiForgeryToken]    // Protects against CSRF attacks by validating token
        public async Task<IActionResult> CreateForCustomer(CreateBookingViewModel model)
        {
            // Retrieve the authenticated user details from ASP.NET Identity
            var user = await _userManager.GetUserAsync(User);    // Get ApplicationUser from current request User
            if (user == null)                                    // Verify user is authenticated
            {
                return Challenge();                               // Return challenge response to redirect to login
            }

            if (!ModelState.IsValid)                             // Check if form validation passed
            {
                // Re-populate dropdown lists for the form on validation error
                await PopulateCreateLists(model);                // Call helper method to repopulate dropdowns
                return View(model);                              // Return view with validation errors displayed
            }

            // Retrieve the selected service with its provider details
            var service = await _context.Services                // Query Services table
                .Include(s => s.ServiceProvider)                 // Eager load ServiceProvider relation
                    .ThenInclude(sp => sp.ApplicationUser)       // Then load ApplicationUser details
                .FirstOrDefaultAsync(s => s.Id == model.ServiceId); // Find service by ID from form

            // Retrieve the selected time slot with its provider details
            var availability = await _context.Availabilities     // Query Availabilities table
                .Include(a => a.ServiceProvider)                 // Eager load ServiceProvider relation
                    .ThenInclude(sp => sp.ApplicationUser)       // Then load ApplicationUser details
                .FirstOrDefaultAsync(a => a.Id == model.AvailabilityId); // Find availability by ID from form

            // Validate that both service and availability were found
            if (service == null || availability == null)         // Business logic validation
            {
                ModelState.AddModelError(string.Empty, "Invalid service or time slot."); // Add error message to ModelState
                await PopulateCreateLists(model);                // Repopulate dropdowns
                return View(model);                              // Return view with error messages
            }

            // Verify that the selected time slot belongs to the chosen service provider
            if (availability.ServiceProviderId != service.ServiceProviderId) // Security/ownership check
            {
                ModelState.AddModelError(string.Empty, "Selected time slot does not belong to the selected service provider."); // Add error
                await PopulateCreateLists(model);                // Repopulate dropdowns
                return View(model);                              // Return view with error
            }

            // Check if the time slot is already booked by someone else
            if (availability.IsBooked)                           // Concurrency/availability check
            {
                ModelState.AddModelError(string.Empty, "Selected time slot is already booked."); // Add error message
                await PopulateCreateLists(model);                // Repopulate dropdowns
                return View(model);                              // Return view with error
            }

            // Instantiate new Booking entity with form data
            var booking = new Booking                             // Create new Booking object
            {
                CustomerId = user.Id,                            // Set customer ID from authenticated user
                ServiceProviderId = service.ServiceProviderId,   // Set provider ID from selected service
                ServiceId = service.Id,                          // Set service ID from selected service
                AvailabilityId = availability.Id,                // Set availability ID from selected slot
                BookingDate = DateTime.Now,                      // Set booking creation timestamp to current time
                Status = BookingStatus.Pending,                  // Set initial status to pending approval
                CancelReason = string.Empty                      // Initialize cancel reason as empty string
            };

            availability.IsBooked = true;                        // Mark the time slot as booked to prevent double-booking
            _context.Bookings.Add(booking);                      // Add new booking to Entity Framework context
            await _context.SaveChangesAsync();                  // Save changes to database (both booking and availability update)

            // Find the service provider for notification purposes
            var provider = await _context.ServiceProviders       // Query ServiceProviders table
                .Include(sp => sp.ApplicationUser)               // Include ApplicationUser for notification details
                .FirstOrDefaultAsync(sp => sp.Id == service.ServiceProviderId); // Find provider by ID

            if (provider?.ApplicationUser != null)               // Verify provider and user exist
            {
                var notification = new Notification              // Create notification for provider
                {
                    UserId = provider.UserId,                    // Send notification to provider's account
                    BookingId = booking.Id,                      // Reference the booking ID
                    Message = $"New booking request from {user.FullName} for {service.Name} on {availability.AvailableDate:yyyy/MM/dd} at {availability.StartTime:hh\\:mm}.", // Format notification message
                    IsRead = false,                              // Mark as unread
                    CreatedAt = DateTime.Now                     // Set creation timestamp
                };
                _context.Notifications.Add(notification);        // Add notification to database context
            }

            // Create confirmation notification for customer
            var customerNotification = new Notification          // Create notification for customer
            {
                UserId = user.Id,                                // Send to the customer who made the booking
                BookingId = booking.Id,                          // Reference the booking
                Message = $"Your booking #{booking.Id} for {service.Name} has been submitted and is awaiting provider approval.", // Confirmation message
                IsRead = false,                                  // Mark as unread
                CreatedAt = DateTime.Now                         // Set creation timestamp
            };
            _context.Notifications.Add(customerNotification);   // Add notification to database context

            await _context.SaveChangesAsync();                  // Save all notifications to database

            return RedirectToAction(nameof(MyBookings));        // Redirect to customer's bookings list
        }

        // Helper method - Populates dropdown lists for CreateForCustomer form based on selected service and category
        private async Task PopulateCreateLists(CreateBookingViewModel model)
        {
            var servicesQuery = _context.Services           // Query Services table
                .Include(s => s.ServiceProvider)             // Include provider relation
                    .ThenInclude(sp => sp.ApplicationUser)   // Include user details for provider
                .AsQueryable();                              // Make it queryable for filtering

            if (!string.IsNullOrWhiteSpace(model.CategoryFilter)) // Check if category filter is applied
            {
                servicesQuery = servicesQuery.Where(s => s.Category == model.CategoryFilter); // Filter services by category
            }

            var services = await servicesQuery              // Execute services query
                .OrderBy(s => s.Category)                   // Sort by category first
                .ThenBy(s => s.Name)                        // Then by service name
                .ToListAsync();                             // Get results as list

            var availabilitiesQuery = _context.Availabilities // Query Availabilities table
                .Include(a => a.ServiceProvider)             // Include provider details
                    .ThenInclude(sp => sp.ApplicationUser)   // Include user details
                .Where(a => !a.IsBooked && a.AvailableDate >= DateTime.Today); // Filter: available slots, future dates only

            if (model.ServiceId > 0)                        // Check if specific service is selected
            {
                var svc = services.FirstOrDefault(s => s.Id == model.ServiceId); // Find selected service
                if (svc != null)                            // If service found
                {
                    availabilitiesQuery = availabilitiesQuery.Where(a => a.ServiceProviderId == svc.ServiceProviderId); // Filter slots by provider
                    model.SelectedService = svc;            // Set selected service in view model
                }
            }

            var availabilities = await availabilitiesQuery  // Execute availability query
                .OrderBy(a => a.AvailableDate)               // Sort by date ascending
                .ThenBy(a => a.StartTime)                    // Then by start time ascending
                .ToListAsync();                              // Get results as list

            var distinctCategories = await _context.Services // Query distinct categories from services
                .Select(s => s.Category)                     // Select Category property
                .Distinct()                                  // Remove duplicates
                .OrderBy(c => c)                             // Sort alphabetically
                .ToListAsync();                              // Get results as list

            var distinctRegions = await _context.ServiceProviders // Query distinct regions from providers
                .Where(sp => sp.CoveredAreas != null && sp.CoveredAreas != "") // Filter non-empty
                .Select(sp => sp.CoveredAreas)                    // Select CoveredAreas property
                .Distinct()                                       // Remove duplicates
                .OrderBy(r => r)                                 // Sort alphabetically
                .ToListAsync();                                  // Get results as list

            model.Services = services.Select(s => new SelectListItem // Transform services to SelectListItems
            {
                Value = s.Id.ToString(),                     // Service ID as option value
                Text = $"{s.Name} ({s.Category}) - {s.ServiceProvider?.ApplicationUser?.FullName}" // Formatted display text
            }).ToList();

            model.Availabilities = availabilities.Select(a => new SelectListItem // Transform availabilities to SelectListItems
            {
                Value = a.Id.ToString(),                     // Availability ID as option value
                Text = $"{a.AvailableDate:yyyy/MM/dd} {a.StartTime:hh\\:mm}-{a.EndTime:hh\\:mm} - {a.ServiceProvider?.ApplicationUser?.FullName}" // Formatted slot text
            }).ToList();

            model.Categories = distinctCategories.Select(c => new SelectListItem // Transform categories to SelectListItems
            {
                Value = c,                                   // Category as option value
                Text = c,                                    // Category as display text
                Selected = c == model.CategoryFilter         // Mark selected if matches current filter
            }).ToList();

            model.Regions = distinctRegions.Select(r => new SelectListItem // Transform regions to SelectListItems
            {
                Value = r,                                   // Region as option value
                Text = r,                                    // Region as display text
                Selected = r == model.RegionFilter           // Mark selected if matches current filter
            }).ToList();
        }



        // ---------- Customer Bookings ----------

        // GET: Bookings/MyBookings - Shows customer's all bookings with status, used by MyBookings.cshtml
        // CALLABLE BY: Customer only - View and manage personal booking history
        [Authorize(Roles = "Customer")]                          // Restricts access to users with "Customer" role only
        public async Task<IActionResult> MyBookings()
        {
            var user = await _userManager.GetUserAsync(User);   // Retrieve authenticated user from ASP.NET Identity
            if (user == null)                                    // Verify user authentication
            {
                return Challenge();                              // Redirect to login if not authenticated
            }

            var bookings = await _context.Bookings               // Query Bookings table
                .Include(b => b.Service)                         // Load related Service details
                .Include(b => b.ServiceProvider)                 // Load provider relationship
                    .ThenInclude(sp => sp.ApplicationUser)       // Then load provider's user details for display names
                .Include(b => b.Availability)                    // Load time slot details
                .Include(b => b.Review)                          // Load review data to check for existing reviews
                .Where(b => b.CustomerId == user.Id)             // Filter bookings to current customer's bookings only
                .OrderByDescending(b => b.BookingDate)           // Sort by booking date descending (newest first)
                .ToListAsync();                                  // Execute query and get List<Booking>

            return View(bookings);                               // Return view with customer's booking list
        }

        // GET: Bookings/CreateReview/5 - Shows review form for completed booking, used by CreateReview.cshtml
        [Authorize(Roles = "Customer")]                          // Restricts access to users with "Customer" role only
        public async Task<IActionResult> CreateReview(int? id)   // Parameters: id - Booking ID to review
        {
            if (id == null)                                     // Check if booking ID parameter is missing
            {
                return NotFound();                              // Return 404 if no ID provided
            }

            var user = await _userManager.GetUserAsync(User);   // Get currently authenticated user
            if (user == null)                                    // Verify user authentication
            {
                return Challenge();                              // Redirect to login if not authenticated
            }

            var booking = await _context.Bookings                // Query Bookings table
                .Include(b => b.Service)                         // Load service details
                .Include(b => b.ServiceProvider)                 // Load provider relationship
                    .ThenInclude(sp => sp.ApplicationUser)       // Load provider's user details
                .Include(b => b.Availability)                    // Load time slot details
                .Include(b => b.Review)                          // Load existing review data to check duplicates
                .FirstOrDefaultAsync(b => b.Id == id && b.CustomerId == user.Id); // Find booking by ID and ensure ownership

            if (booking == null)                                 // Check if booking exists and belongs to user
            {
                return NotFound();                              // Return 404 if booking not found or wrong user
            }

            if (booking.Status != BookingStatus.Completed)      // Verify booking is completed
            {
                TempData["ErrorMessage"] = "You can only review completed bookings."; // Set error message in TempData
                return RedirectToAction(nameof(MyBookings));     // Redirect back to bookings list
            }

            if (booking.Review != null)                          // Check if review already exists
            {
                TempData["ErrorMessage"] = "You have already reviewed this booking."; // Set error message
                return RedirectToAction(nameof(MyBookings));     // Redirect back to bookings list
            }

            return View(booking);                               // Return view with booking data for review form
        }

        // GET: Bookings/ProviderBookingHistory - Shows provider's past bookings, used by ProviderBookingHistory.cshtml
        [Authorize(Roles = "ServiceProvider")]                   // Restricts access to users with "ServiceProvider" role only
        public async Task<IActionResult> ProviderBookingHistory()
        {
            var user = await _userManager.GetUserAsync(User);   // Get currently authenticated user
            if (user == null)                                    // Verify user authentication
            {
                return Challenge();                              // Redirect to login if not authenticated
            }

            var provider = await _context.ServiceProviders       // Query ServiceProviders table
                .Include(sp => sp.ApplicationUser)               // Load user details
                .FirstOrDefaultAsync(sp => sp.UserId == user.Id); // Find provider profile for this user

            if (provider == null)                                 // Check if provider profile exists
            {
                return NotFound();                              // Return 404 if user is not a provider
            }

            var bookings = await _context.Bookings               // Query Bookings table
                .Include(b => b.Customer)                        // Load customer details
                .Include(b => b.Service)                         // Load service details
                .Include(b => b.Availability)                    // Load time slot details
                .Where(b => b.ServiceProviderId == provider.Id &&
                            b.Status != BookingStatus.Pending)   // Filter: provider's bookings, exclude pending requests
                .OrderByDescending(b => b.BookingDate)           // Sort by booking date descending (newest first)
                .ToListAsync();                                  // Execute query and get List<Booking>

            return View(bookings);                               // Return view with provider's booking history
        }

        // POST: Bookings/CreateReview/5 - Processes customer review submission, used by CreateReview.cshtml
        [Authorize(Roles = "Customer")]                         // Restricts access to users with "Customer" role only
        [HttpPost]                                             // Handles HTTP POST requests
        [ValidateAntiForgeryToken]                             // Protects against CSRF attacks
        public async Task<IActionResult> CreateReview(int id, int rating, string comment) // Parameters: booking ID, rating value, comment text
        {
            var user = await _userManager.GetUserAsync(User);  // Get currently authenticated user
            if (user == null)                                   // Verify user authentication
            {
                return Challenge();                             // Redirect to login if not authenticated
            }

            var booking = await _context.Bookings               // Query Bookings table
                .Include(b => b.ServiceProvider)                // Load provider details for review association
                .Include(b => b.Review)                         // Load existing review to check for duplicates
                .FirstOrDefaultAsync(b => b.Id == id && b.CustomerId == user.Id); // Find booking by ID and verify ownership

            if (booking == null)                                // Check if booking exists and belongs to user
            {
                return NotFound();                             // Return 404 if booking not found
            }

            if (booking.Status != BookingStatus.Completed)     // Validate that the booking is completed
            {
                TempData["ErrorMessage"] = "You can only review completed bookings."; // Set error message in session
                return RedirectToAction(nameof(MyBookings));    // Redirect to bookings list
            }

            if (booking.Review != null)                         // Check if review already exists
            {
                TempData["ErrorMessage"] = "You have already reviewed this booking."; // Set error message
                return RedirectToAction(nameof(MyBookings));    // Redirect to bookings list
            }

            if (rating < 1 || rating > 5)                       // Validate rating range
            {
                ModelState.AddModelError("", "Rating must be between 1 and 5."); // Add validation error
                return View(booking);                           // Return view with validation errors
            }

            var review = new Review                             // Create new Review entity
            {
                BookingId = booking.Id,                         // Link review to booking
                ReviewerId = user.Id,                           // Set reviewer ID (customer)
                ServiceProviderId = booking.ServiceProviderId,  // Associate review with provider
                Rating = rating,                                // Set rating value
                Comment = comment ?? string.Empty,              // Set comment (handle null)
                IsVisible = true,                               // Set review as visible (default)
                CreatedAt = DateTime.Now                        // Set creation timestamp
            };

            _context.Reviews.Add(review);                       // Add review to database context

            // Recalculate provider's average rating
            var allReviews = await _context.Reviews.Where(r => r.ServiceProviderId == booking.ServiceProviderId).ToListAsync(); // Get all provider reviews
            float newRating = allReviews.Count > 0 ? (float)allReviews.Average(r => r.Rating) : 0f; // Calculate average rating

            var provider = await _context.ServiceProviders.FindAsync(booking.ServiceProviderId); // Retrieve provider for update
            if (provider != null)                               // Verify provider exists
            {
                provider.Rating = newRating;                   // Update provider's rating
            }

            await _context.SaveChangesAsync();                 // Save all changes (review and provider rating)

            TempData["SuccessMessage"] = "Your review has been submitted successfully!"; // Set success message
            return RedirectToAction(nameof(MyBookings));       // Redirect to bookings list
        }

        // POST: Bookings/Cancel/5 - Customer cancels booking with 12hr policy, used by MyBookings.cshtml
        [Authorize(Roles = "Customer")]                         // Restricts access to users with "Customer" role only
        [HttpPost]                                             // Handles HTTP POST requests
        [ValidateAntiForgeryToken]                             // Protects against CSRF attacks
        public async Task<IActionResult> Cancel(int id)        // Parameters: booking ID to cancel
        {
            var user = await _userManager.GetUserAsync(User);  // Get currently authenticated user
            if (user == null)                                   // Verify user authentication
            {
                return Challenge();                             // Redirect to login if not authenticated
            }

            var booking = await _context.Bookings               // Query Bookings table
                .Include(b => b.Availability)                    // Load time slot details (for time checking and unbooking)
                .Include(b => b.Service)                         // Load service details for notification
                .Include(b => b.ServiceProvider)                 // Load provider relationship
                    .ThenInclude(sp => sp.ApplicationUser)       // Load provider's user details for notification
                .FirstOrDefaultAsync(b => b.Id == id);          // Find booking by ID

            if (booking == null)                                // Check if booking exists
            {
                return NotFound();                             // Return 404 if booking not found
            }

            if (booking.CustomerId != user.Id)                  // Verify ownership (customer can only cancel their own bookings)
            {
                return Forbid();                                // Return 403 Forbidden if wrong customer
            }

            if (booking.Status == BookingStatus.Completed || booking.Status == BookingStatus.Cancelled) // Check if booking can be cancelled
            {
                return RedirectToAction(nameof(MyBookings));    // Redirect if booking already completed or cancelled
            }

            // Enforce 12-hour cancellation policy
            if (booking.Availability != null)                   // Verify availability exists (defensive check)
            {
                var bookingStartTime = booking.Availability.AvailableDate.Add(booking.Availability.StartTime); // Calculate booking start time
                var hoursUntilBooking = (bookingStartTime - DateTime.Now).TotalHours; // Calculate hours remaining

                if (hoursUntilBooking < 12)                      // Check if less than 12 hours before booking
                {
                    TempData["ErrorMessage"] = "You can only cancel the booking at least 12 hours before the scheduled time."; // Set error message
                    return RedirectToAction(nameof(MyBookings)); // Redirect back to bookings list with error
                }
            }

            // Notify provider about the cancellation before removing the booking
            if (booking.ServiceProvider?.ApplicationUser != null) // Verify provider and user exist
            {
                var notifProvider = new Notification             // Create notification for provider
                {
                    UserId = booking.ServiceProvider.UserId,    // Send to provider's account
                    BookingId = booking.Id,                     // Reference the booking ID
                    Message = $"Booking #{booking.Id} for {booking.Service?.Name} was cancelled by the customer.", // Cancellation message
                    IsRead = false,                             // Mark as unread
                    CreatedAt = DateTime.Now                    // Set creation timestamp
                };
                _context.Notifications.Add(notifProvider);      // Add notification to database context
            }

            // Free up the time slot by unbooking the availability
            if (booking.Availability != null)                   // Verify availability exists (defensive check)
            {
                booking.Availability.IsBooked = false;         // Set availability as unbooked (allows rebooking)
            }

            _context.Bookings.Remove(booking);                 // Remove booking from database

            await _context.SaveChangesAsync();                 // Save all changes (notification, availability update, booking removal)

            return RedirectToAction(nameof(MyBookings));       // Redirect back to customer's bookings list
        }

        // ---------- Service Provider Bookings ----------

        // GET: Bookings/ProviderNewBookings - Shows pending booking requests, used by ProviderNewBookings.cshtml
        [Authorize(Roles = "ServiceProvider")]                   // Restricts access to users with "ServiceProvider" role only
        public async Task<IActionResult> ProviderNewBookings()
        {
            var user = await _userManager.GetUserAsync(User);   // Get currently authenticated user
            if (user == null)                                    // Verify user authentication
            {
                return Challenge();                              // Redirect to login if not authenticated
            }

            var provider = await _context.ServiceProviders       // Query ServiceProviders table
                .Include(sp => sp.ApplicationUser)               // Load user details for provider
                .FirstOrDefaultAsync(sp => sp.UserId == user.Id); // Find provider profile for this user

            if (provider == null)                                 // Check if provider profile exists
            {
                return NotFound();                              // Return 404 if user is not a provider
            }

            var bookings = await _context.Bookings               // Query Bookings table
                .Include(b => b.Customer)                        // Load customer details
                .Include(b => b.Service)                         // Load service details
                .Include(b => b.Availability)                    // Load time slot details
                .Where(b => b.ServiceProviderId == provider.Id &&
                            b.Status == BookingStatus.Pending)   // Filter: provider's bookings, include only pending requests
                .OrderBy(b => b.Availability.AvailableDate)      // Sort by booking date ascending
                .ThenBy(b => b.Availability.StartTime)           // Then by start time ascending
                .ToListAsync();                                  // Execute query and get List<Booking>

            return View(bookings);                               // Return view with pending booking requests
        }


        // POST: Bookings/Accept/5 - Provider accepts booking request, sends notifications, used by ProviderNewBookings.cshtml
        [Authorize(Roles = "ServiceProvider")]                   // Restricts access to users with "ServiceProvider" role only
        [HttpPost]                                             // Handles HTTP POST requests
        [ValidateAntiForgeryToken]                             // Protects against CSRF attacks
        public async Task<IActionResult> Accept(int id)        // Parameters: booking ID to accept
        {
            var user = await _userManager.GetUserAsync(User);  // Get currently authenticated user
            if (user == null)                                   // Verify user authentication
            {
                return Challenge();                             // Redirect to login if not authenticated
            }

            var provider = await _context.ServiceProviders       // Query ServiceProviders table
                .FirstOrDefaultAsync(sp => sp.UserId == user.Id); // Find provider profile for this user

            if (provider == null)                                 // Check if provider profile exists
            {
                return NotFound();                              // Return 404 if user is not a provider
            }

            var booking = await _context.Bookings               // Query Bookings table
                .Include(b => b.Customer)                        // Load customer details for notification
                .Include(b => b.Service)                         // Load service details for notification
                .Include(b => b.Availability)                    // Load time slot details
                .FirstOrDefaultAsync(b => b.Id == id);          // Find booking by ID

            if (booking == null)                                // Check if booking exists
            {
                return NotFound();                             // Return 404 if booking not found
            }

            if (booking.ServiceProviderId != provider.Id)       // Verify ownership (provider can only accept their own bookings)
            {
                return Forbid();                                // Return 403 Forbidden if wrong provider
            }

            if (booking.Status != BookingStatus.Pending)        // Check if booking is still pending
            {
                return RedirectToAction(nameof(ProviderNewBookings)); // Redirect if booking status changed
            }

            booking.Status = BookingStatus.Accepted;            // Update booking status to accepted
            booking.CancelReason = string.Empty;                // Clear any cancel reason for accepted bookings

            // Create notification for customer about acceptance
            var notifCustomer = new Notification               // Instantiate Notification entity
            {
                UserId = booking.CustomerId,                   // Send to customer who made booking
                BookingId = booking.Id,                        // Reference the booking
                Message = $"Your booking #{booking.Id} for {booking.Service?.Name} has been accepted.", // Formatted acceptance message
                IsRead = false,                                // Mark as unread
                CreatedAt = DateTime.Now                       // Set creation timestamp
            };
            _context.Notifications.Add(notifCustomer);         // Add notification to database context

            await _context.SaveChangesAsync();                 // Save status change and notification

            return RedirectToAction(nameof(ProviderNewBookings)); // Redirect back to pending bookings list
        }


        // POST: Bookings/Reject/5 - Provider rejects booking with reason, used by ProviderNewBookings.cshtml
        [Authorize(Roles = "ServiceProvider")]                   // Restricts access to users with "ServiceProvider" role only
        [HttpPost]                                             // Handles HTTP POST requests
        [ValidateAntiForgeryToken]                             // Protects against CSRF attacks
        public async Task<IActionResult> Reject(int id, string? reason) // Parameters: booking ID to reject, optional rejection reason
        {
            var user = await _userManager.GetUserAsync(User);  // Get currently authenticated user
            if (user == null)                                   // Verify user authentication
            {
                return Challenge();                             // Redirect to login if not authenticated
            }

            var provider = await _context.ServiceProviders       // Query ServiceProviders table
                .FirstOrDefaultAsync(sp => sp.UserId == user.Id); // Find provider profile for this user

            if (provider == null)                                 // Check if provider profile exists
            {
                return NotFound();                              // Return 404 if user is not a provider
            }

            var booking = await _context.Bookings               // Query Bookings table
                .Include(b => b.Customer)                        // Load customer details for notification
                .Include(b => b.Service)                         // Load service details for notification
                .Include(b => b.Availability)                    // Load time slot details for unbooking
                .FirstOrDefaultAsync(b => b.Id == id);          // Find booking by ID

            if (booking == null)                                // Check if booking exists
            {
                return NotFound();                             // Return 404 if booking not found
            }

            if (booking.ServiceProviderId != provider.Id)       // Verify ownership (provider can only reject their own bookings)
            {
                return Forbid();                                // Return 403 Forbidden if wrong provider
            }

            if (booking.Status != BookingStatus.Pending)        // Check if booking is still pending
            {
                return RedirectToAction(nameof(ProviderNewBookings)); // Redirect if booking status changed
            }

            // Provide default rejection reason if none provided
            if (string.IsNullOrWhiteSpace(reason))              // Check if reason is empty/null/whitespace
            {
                reason = "Your booking was rejected by the provider."; // Set default rejection message
            }

            booking.Status = BookingStatus.Rejected;            // Update booking status to rejected
            booking.CancelReason = reason;                      // Set rejection reason

            // Unbook the availability slot to make it available again
            if (booking.Availability != null)                   // Verify availability exists (defensive check)
            {
                booking.Availability.IsBooked = false;         // Free up the time slot for other bookings
            }

            // Create notification for customer about rejection
            var notifCustomer = new Notification               // Instantiate Notification entity
            {
                UserId = booking.CustomerId,                   // Send to customer who made booking
                BookingId = booking.Id,                        // Reference the booking
                Message = $"Your booking #{booking.Id} for {booking.Service?.Name} was rejected. Reason: {reason}", // Formatted rejection message with reason
                IsRead = false,                                // Mark as unread
                CreatedAt = DateTime.Now                       // Set creation timestamp
            };
            _context.Notifications.Add(notifCustomer);         // Add notification to database context

            await _context.SaveChangesAsync();                 // Save status change, unbooking, and notification

            // Note: We don't delete the booking, just change its status to Rejected
            return RedirectToAction(nameof(ProviderNewBookings)); // Redirect back to pending bookings list
        }


        // POST: Bookings/Complete/5 - Provider marks service as completed, sends notifications, used by ProviderBookingHistory.cshtml
        [Authorize(Roles = "ServiceProvider")]                   // Restricts access to users with "ServiceProvider" role only
        [HttpPost]                                             // Handles HTTP POST requests
        [ValidateAntiForgeryToken]                             // Protects against CSRF attacks
        public async Task<IActionResult> Complete(int id)     // Parameters: booking ID to mark as completed
        {
            var user = await _userManager.GetUserAsync(User);  // Get currently authenticated user
            if (user == null)                                   // Verify user authentication
            {
                return Challenge();                             // Redirect to login if not authenticated
            }

            var provider = await _context.ServiceProviders       // Query ServiceProviders table
                .FirstOrDefaultAsync(sp => sp.UserId == user.Id); // Find provider profile for this user

            if (provider == null)                                 // Check if provider profile exists
            {
                return NotFound();                              // Return 404 if user is not a provider
            }

            var booking = await _context.Bookings               // Query Bookings table
                .Include(b => b.Customer)                        // Load customer details for notification
                .Include(b => b.Service)                         // Load service details for notification
                .Include(b => b.Availability)                    // Load time slot details
                .FirstOrDefaultAsync(b => b.Id == id);          // Find booking by ID

            if (booking == null)                                // Check if booking exists
            {
                return NotFound();                             // Return 404 if booking not found
            }

            if (booking.ServiceProviderId != provider.Id)       // Verify ownership (provider can only complete their own bookings)
            {
                return Forbid();                                // Return 403 Forbidden if wrong provider
            }

            if (booking.Status != BookingStatus.Accepted)       // Check if booking is accepted (can only complete accepted bookings)
            {
                return RedirectToAction(nameof(ProviderBookingHistory)); // Redirect if booking status wrong
            }

            booking.Status = BookingStatus.Completed;           // Update booking status to completed

            // Create notification for customer about completion and review invitation
            var notifCustomer = new Notification               // Instantiate Notification entity
            {
                UserId = booking.CustomerId,                   // Send to customer who made booking
                BookingId = booking.Id,                        // Reference the booking
                Message = $"Service completed! Please leave a review for '{booking.Service?.Name}' by visiting your bookings.", // Completion message with review invite
                IsRead = false,                                // Mark as unread
                CreatedAt = DateTime.Now                       // Set creation timestamp
            };
            _context.Notifications.Add(notifCustomer);         // Add notification to database context

            await _context.SaveChangesAsync();                 // Save status change and notification

            return RedirectToAction(nameof(ProviderBookingHistory)); // Redirect back to booking history list
        }

        // Helper method - Checks if booking exists by ID, used in edit operations to detect concurrency conflicts
        private bool BookingExists(int id)                      // Parameters: booking ID to check
        {
            return _context.Bookings.Any(e => e.Id == id);     // Query Bookings table and check if any booking with given ID exists
        }


    }
}
