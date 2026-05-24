using System;

namespace mike2.Models
{
    public class Notification
    {
        public int Id { get; set; }              // PK

        public string UserId { get; set; }       // FK → ApplicationUser
        public ApplicationUser User { get; set; }

        public int? BookingId { get; set; }      // FK nullable → Booking
        public Booking Booking { get; set; }

        public string Message { get; set; }
        public bool IsRead { get; set; }
        public DateTime CreatedAt { get; set; }
    }
}
