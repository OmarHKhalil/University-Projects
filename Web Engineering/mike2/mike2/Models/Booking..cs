using System;
using System.ComponentModel.DataAnnotations;

namespace mike2.Models
{
    public enum BookingStatus
    {
        Pending = 0,
        Accepted = 1,
        Rejected = 2,
        Cancelled = 3,
        Completed = 4
    }

    public class Booking
    {
        public int Id { get; set; }                 // PK

        // Customer (USER)
        public string CustomerId { get; set; }      // FK → ApplicationUser
        public ApplicationUser Customer { get; set; }

        // Provider
        public int ServiceProviderId { get; set; }  // FK → AppServiceProvider
        public AppServiceProvider ServiceProvider { get; set; }

        // Service
        public int ServiceId { get; set; }          // FK → Service
        public Service Service { get; set; }

        // Availability
        public int? AvailabilityId { get; set; }     // FK UNIQUE → Availability (nullable for rejected bookings)
        public Availability Availability { get; set; }

        public DateTime BookingDate { get; set; }
        public BookingStatus Status { get; set; }
        public string CancelReason { get; set; }

        // العلاقات الأخرى
        public Review Review { get; set; }                             // 1 : 1
        public ICollection<Notification> Notifications { get; set; }
            = new List<Notification>();                                // 1 : N
    }
}
