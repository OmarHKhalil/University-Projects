using System;

namespace mike2.Models
{
    public class Review
    {
        public int Id { get; set; }              // PK

        public int BookingId { get; set; }       // FK UNIQUE → Booking
        public Booking Booking { get; set; }

        public string ReviewerId { get; set; }   // FK → ApplicationUser (USER)
        public ApplicationUser Reviewer { get; set; }

        public int ServiceProviderId { get; set; }  // FK → AppServiceProvider
        public AppServiceProvider ServiceProvider { get; set; }

        public int Rating { get; set; }
        public string Comment { get; set; }
        public bool IsVisible { get; set; }
        public DateTime CreatedAt { get; set; }
    }
}
