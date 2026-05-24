using Microsoft.AspNetCore.Identity;
using System.Collections.Generic;

namespace mike2.Models
{
    // أضِف هاد الجزء فوق الكلاس
    public enum UserRole
    {
        Customer = 0,
        ServiceProvider = 1,
        Admin = 2
    }

    public class ApplicationUser : IdentityUser
    {
        public string FullName { get; set; } = string.Empty;
        public string Location { get; set; } = string.Empty;

        public UserRole Role { get; set; } = UserRole.Customer;  // قيمة افتراضية
        public bool IsActive { get; set; } = true;

        public AppServiceProvider ServiceProvider { get; set; }
        public ICollection<Booking> Bookings { get; set; } = new List<Booking>();
        public ICollection<Review> Reviews { get; set; } = new List<Review>();
        public ICollection<Notification> Notifications { get; set; } = new List<Notification>();
    }
}
