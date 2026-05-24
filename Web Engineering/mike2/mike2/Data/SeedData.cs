using System;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Identity;
using Microsoft.Extensions.DependencyInjection;
using mike2.Models;

namespace mike2.Data
{
    /// <summary>
    /// تهيئة الأدوار الأساسية وإنشاء مستخدم مشرف افتراضي مع شوية بيانات بسيطة.
    /// استدعِ هذه الدالة من Program.cs عند تشغيل التطبيق.
    /// </summary>
    public static class SeedData
    {
        public static async Task InitializeAsync(IServiceProvider serviceProvider)
        {
            using var scope = serviceProvider.CreateScope();

            var roleManager = scope.ServiceProvider.GetRequiredService<RoleManager<IdentityRole>>();
            var userManager = scope.ServiceProvider.GetRequiredService<UserManager<ApplicationUser>>();
            var db = scope.ServiceProvider.GetRequiredService<ApplicationDbContext>();

            // 1) إنشاء الأدوار الأساسية إذا لم تكن موجودة
            string[] roles = { "Admin", "Customer", "ServiceProvider" };

            foreach (var role in roles)
            {
                if (!await roleManager.RoleExistsAsync(role))
                {
                    await roleManager.CreateAsync(new IdentityRole(role));
                }
            }

            // 2) إنشاء مستخدم Admin افتراضي (إذا لم يكن موجوداً)
            const string adminEmail = "admin@demo.com";
            const string adminUserName = "admin@demo.com";
            const string adminPassword = "Admin123!"; // فقط للتجربة

            var adminUser = await userManager.FindByEmailAsync(adminEmail);
            if (adminUser == null)
            {
                adminUser = new ApplicationUser
                {
                    UserName = adminUserName,
                    Email = adminEmail,
                    EmailConfirmed = true,
                    FullName = "Default Admin",
                    Location = "Head Office",
                    Role = UserRole.Admin,
                    IsActive = true
                };

                var result = await userManager.CreateAsync(adminUser, adminPassword);
                if (result.Succeeded)
                {
                    await userManager.AddToRoleAsync(adminUser, "Admin");
                }
            }
            else
            {
                // تأكد أنه يملك دور Admin وقيمته في الـ enum صحيحة
                if (!await userManager.IsInRoleAsync(adminUser, "Admin"))
                {
                    await userManager.AddToRoleAsync(adminUser, "Admin");
                }

                if (adminUser.Role != UserRole.Admin)
                {
                    adminUser.Role = UserRole.Admin;
                    await userManager.UpdateAsync(adminUser);
                }
            }

            // 3) إذا كان لا توجد بيانات، نضيف بيانات تجريبية بسيطة
            if (!db.Users.Any(u => u.Role == UserRole.Customer))
            {
                // عملاء
                var customer1 = new ApplicationUser
                {
                    UserName = "customer1@demo.com",
                    Email = "customer1@demo.com",
                    EmailConfirmed = true,
                    FullName = "أحمد الزبون",
                    Location = "دمشق",
                    Role = UserRole.Customer,
                    IsActive = true
                };
                var customer2 = new ApplicationUser
                {
                    UserName = "customer2@demo.com",
                    Email = "customer2@demo.com",
                    EmailConfirmed = true,
                    FullName = "سارة الزبونة",
                    Location = "حلب",
                    Role = UserRole.Customer,
                    IsActive = true
                };

                await userManager.CreateAsync(customer1, "Customer123!");
                await userManager.AddToRoleAsync(customer1, "Customer");
                await userManager.CreateAsync(customer2, "Customer123!");
                await userManager.AddToRoleAsync(customer2, "Customer");
            }

            if (!db.Users.Any(u => u.Role == UserRole.ServiceProvider))
            {
                // مقدمو خدمة (Users)
                var spUser1 = new ApplicationUser
                {
                    UserName = "cleaner1@demo.com",
                    Email = "cleaner1@demo.com",
                    EmailConfirmed = true,
                    FullName = "شركة نظافة الشام",
                    Location = "دمشق",
                    Role = UserRole.ServiceProvider,
                    IsActive = true
                };
                var spUser2 = new ApplicationUser
                {
                    UserName = "electric1@demo.com",
                    Email = "electric1@demo.com",
                    EmailConfirmed = true,
                    FullName = "كهربائي الخبرة",
                    Location = "دمشق",
                    Role = UserRole.ServiceProvider,
                    IsActive = true
                };

                await userManager.CreateAsync(spUser1, "Provider123!");
                await userManager.AddToRoleAsync(spUser1, "ServiceProvider");
                await userManager.CreateAsync(spUser2, "Provider123!");
                await userManager.AddToRoleAsync(spUser2, "ServiceProvider");

                // حفظ حتى نحصل على الـ Ids
                await db.SaveChangesAsync();

                // ربطهم بـ AppServiceProvider
                var provider1 = new AppServiceProvider
                {
                    UserId = spUser1.Id,
                    ApplicationUser = spUser1,
                    Experience = "5 سنوات خبرة في تنظيف المنازل.",
                    Specializations = "تنظيف شقق - تنظيف مكاتب",
                    CoveredAreas = "دمشق - ريف دمشق",
                    Rating = 4.5f
                };
                var provider2 = new AppServiceProvider
                {
                    UserId = spUser2.Id,
                    ApplicationUser = spUser2,
                    Experience = "8 سنوات خبرة في أعمال الكهرباء المنزلية.",
                    Specializations = "تصليح أعطال - تمديد كهرباء",
                    CoveredAreas = "دمشق",
                    Rating = 4.8f
                };

                db.ServiceProviders.Add(provider1);
                db.ServiceProviders.Add(provider2);
                await db.SaveChangesAsync();

                // خدمات لكل مقدم خدمة
                var cleaningService = new Service
                {
                    ServiceProviderId = provider1.Id,
                    ServiceProvider = provider1,
                    Name = "تنظيف منزل 3 ساعات",
                    Category = "تنظيف",
                    Description = "خدمة تنظيف شاملة للمنزل لمدة 3 ساعات.",
                    BasePrice = 150000
                };

                var electricService = new Service
                {
                    ServiceProviderId = provider2.Id,
                    ServiceProvider = provider2,
                    Name = "فحص وصيانة كهرباء المنزل",
                    Category = "كهرباء",
                    Description = "كشف وفحص وصيانة لأعطال الكهرباء في المنزل.",
                    BasePrice = 200000
                };

                db.Services.Add(cleaningService);
                db.Services.Add(electricService);
                await db.SaveChangesAsync();

                // مواعيد متاحة (Availability)
                var today = DateTime.Today;
                var av1 = new Availability
                {
                    ServiceProviderId = provider1.Id,
                    ServiceProvider = provider1,
                    AvailableDate = today.AddDays(1),
                    StartTime = new TimeSpan(10, 0, 0),
                    EndTime = new TimeSpan(13, 0, 0),
                    IsBooked = true // سيُحجز لـ booking1
                };
                var av2 = new Availability
                {
                    ServiceProviderId = provider2.Id,
                    ServiceProvider = provider2,
                    AvailableDate = today.AddDays(2),
                    StartTime = new TimeSpan(16, 0, 0),
                    EndTime = new TimeSpan(18, 0, 0),
                    IsBooked = true // سيُحجز لـ booking2
                };
                // أوقات إضافية متاحة ليتاح الحجز من الواجهة
                var av3 = new Availability
                {
                    ServiceProviderId = provider1.Id,
                    ServiceProvider = provider1,
                    AvailableDate = today.AddDays(3),
                    StartTime = new TimeSpan(9, 0, 0),
                    EndTime = new TimeSpan(12, 0, 0),
                    IsBooked = false
                };
                var av4 = new Availability
                {
                    ServiceProviderId = provider2.Id,
                    ServiceProvider = provider2,
                    AvailableDate = today.AddDays(4),
                    StartTime = new TimeSpan(14, 0, 0),
                    EndTime = new TimeSpan(16, 0, 0),
                    IsBooked = false
                };

                db.Availabilities.Add(av1);
                db.Availabilities.Add(av2);
                db.Availabilities.Add(av3);
                db.Availabilities.Add(av4);
                await db.SaveChangesAsync();

                // نحتاج عملاء من الـ DB بعد الإنشاء
                var customerA = await userManager.FindByEmailAsync("customer1@demo.com");
                var customerB = await userManager.FindByEmailAsync("customer2@demo.com");

                // حجوزات
                var booking1 = new Booking
                {
                    CustomerId = customerA!.Id,
                    Customer = customerA,
                    ServiceProviderId = provider1.Id,
                    ServiceProvider = provider1,
                    ServiceId = cleaningService.Id,
                    Service = cleaningService,
                    AvailabilityId = av1.Id,
                    Availability = av1,
                    BookingDate = today.AddDays(-1),
                    Status = BookingStatus.Completed,
                    CancelReason = string.Empty
                };

                var booking2 = new Booking
                {
                    CustomerId = customerB!.Id,
                    Customer = customerB,
                    ServiceProviderId = provider2.Id,
                    ServiceProvider = provider2,
                    ServiceId = electricService.Id,
                    Service = electricService,
                    AvailabilityId = av2.Id,
                    Availability = av2,
                    BookingDate = today,
                    Status = BookingStatus.Accepted,
                    CancelReason = string.Empty
                };

                db.Bookings.Add(booking1);
                db.Bookings.Add(booking2);
                await db.SaveChangesAsync();

                // تعيين الحجز في الـ Availability (علاقة 1:1)
                av1.Booking = booking1;
                av2.Booking = booking2;
                await db.SaveChangesAsync();

                // تقييمات
                var review1 = new Review
                {
                    BookingId = booking1.Id,
                    Booking = booking1,
                    ReviewerId = customerA.Id,
                    Reviewer = customerA,
                    ServiceProviderId = provider1.Id,
                    ServiceProvider = provider1,
                    Rating = 5,
                    Comment = "خدمة ممتازة وتنظيف رائع.",
                    IsVisible = true,
                    CreatedAt = DateTime.Now.AddHours(-5)
                };

                var review2 = new Review
                {
                    BookingId = booking2.Id,
                    Booking = booking2,
                    ReviewerId = customerB.Id,
                    Reviewer = customerB,
                    ServiceProviderId = provider2.Id,
                    ServiceProvider = provider2,
                    Rating = 3,
                    Comment = "الخدمة جيدة لكن كان هناك تأخير بسيط.",
                    IsVisible = true,
                    CreatedAt = DateTime.Now.AddHours(-2)
                };

                db.Reviews.Add(review1);
                db.Reviews.Add(review2);
                await db.SaveChangesAsync();
            }

            // Clean up rejected bookings to allow rebooking - set AvailabilityId to null
            try
            {
                // Manual filtering since the EF query has type issues
                var allBookings = db.Bookings.ToList(); // Synchronous for simplicity
                var rejectedBookings = allBookings.Where(b => (int)b.Status == 2 && b.AvailabilityId.HasValue).ToList(); // 2 = Rejected

                foreach (var booking in rejectedBookings)
                {
                    booking.AvailabilityId = null;
                    db.Bookings.Update(booking);
                }

                if (rejectedBookings.Any())
                {
                    db.SaveChanges(); // Synchronous
                    Console.WriteLine($"Cleaned up {rejectedBookings.Count} rejected bookings to allow rebooking");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error cleaning up rejected bookings: {ex.Message}");
            }
        }
    }
}
