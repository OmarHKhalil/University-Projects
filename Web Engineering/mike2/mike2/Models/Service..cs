using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using Microsoft.AspNetCore.Mvc.ModelBinding.Validation;

namespace mike2.Models
{
    public class Service
    {
        public int Id { get; set; }                // PK
        public int ServiceProviderId { get; set; } // FK → AppServiceProvider
        [ValidateNever]
        public AppServiceProvider ServiceProvider { get; set; }

        [Required(ErrorMessage = "اسم الخدمة مطلوب.")]
        public string Name { get; set; }
        [Required(ErrorMessage = "فئة الخدمة مطلوبة.")]
        public string Category { get; set; }
        [Required(ErrorMessage = "وصف الخدمة مطلوب.")]
        public string Description { get; set; }
        [Required(ErrorMessage = "السعر الأساسي مطلوب.")]
        public decimal BasePrice { get; set; }

        // العلاقات
        public ICollection<Booking> Bookings { get; set; } = new List<Booking>(); // SERVICE ↔ BOOKING
    }
}
