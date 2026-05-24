using System.Collections.Generic;

namespace mike2.Models
{
    public class AppServiceProvider
    {
        public int Id { get; set; }               // PK
        public string UserId { get; set; }        // FK → ApplicationUser
        public ApplicationUser ApplicationUser { get; set; }

        public string Experience { get; set; }
        public string Specializations { get; set; }
        public string CoveredAreas { get; set; }
        public float Rating { get; set; }

        // العلاقات
        public ICollection<Service> Services { get; set; } = new List<Service>();         // 1 : N
        public ICollection<Availability> Availabilities { get; set; } = new List<Availability>(); // 1 : N
        public ICollection<Booking> Bookings { get; set; } = new List<Booking>();         // 1 : N
        public ICollection<Review> Reviews { get; set; } = new List<Review>();            // 1 : N
    }
}
