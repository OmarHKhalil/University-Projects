using System;
using Microsoft.AspNetCore.Mvc.ModelBinding.Validation;

namespace mike2.Models   // ← هاي أهم سطر
{
    public class Availability
    {
        public int Id { get; set; }
        public int ServiceProviderId { get; set; }

        [ValidateNever]
        public AppServiceProvider ServiceProvider { get; set; }

        public DateTime AvailableDate { get; set; }
        public TimeSpan StartTime { get; set; }
        public TimeSpan EndTime { get; set; }

        public bool IsBooked { get; set; }

        // علاقة 1:1 مع Booking
        [ValidateNever]
        public Booking Booking { get; set; }
    }
}
