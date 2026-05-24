using Microsoft.AspNetCore.Mvc.Rendering;
using mike2.Models;

namespace mike2.ViewModels;

/*
 * ViewModels - نماذج العرض
 *
 * هذه النماذج تحتوي على البيانات المطلوب عرضها في العروض (Views)
 * وتستخدم لجمع البيانات المعقدة من عدة مصادر
 */

/// <summary>
/// نموذج عرض صفحة إنشاء الحجز
/// يجمع معلومات مقدمي الخدمات والخدمات والمراجعات
/// </summary>
public class ServiceWithAvailabilitiesViewModel
{
    public int ServiceId { get; set; }
    public string ServiceName { get; set; } = string.Empty;
    public string Category { get; set; } = string.Empty;
    public string Description { get; set; } = string.Empty;
    public string Region { get; set; } = string.Empty;
    public decimal BasePrice { get; set; }
    public List<Availability> AvailableSlots { get; set; } = new List<Availability>();
}

/// <summary>
/// نموذج عرض مقدم خدمة مع جميع خدماته ومراجعاته
/// يجمع مقدم الخدمة وخدماته وتقييمات العملاء
/// </summary>
public class ProviderWithServicesViewModel
{
    public AppServiceProvider Provider { get; set; } = null!;
    public List<ServiceWithAvailabilitiesViewModel> Services { get; set; } = new List<ServiceWithAvailabilitiesViewModel>();
    public List<Review> RecentReviews { get; set; } = new List<Review>();
    public float AverageRating { get; set; }
    public int TotalReviewCount { get; set; }
}

/// <summary>
/// النموذج الرئيسي لصفحة إنشاء الحجز
/// يحتوي على جميع البيانات المطلوبة لإختيار خدمة وحجز وقت
/// </summary>
public class CreateBookingViewModel
{
    public int ServiceId { get; set; }
    public int AvailabilityId { get; set; }
    public string? CategoryFilter { get; set; }
    public string? RegionFilter { get; set; }
    public int? PriceSort { get; set; } // 1=Ascending, 2=Descending

    // قوائم الإختيار للتصفية والإختيار
    public List<SelectListItem> Categories { get; set; } = new List<SelectListItem>();
    public List<SelectListItem> Regions { get; set; } = new List<SelectListItem>();
    public List<SelectListItem> Services { get; set; } = new List<SelectListItem>();
    public List<SelectListItem> Availabilities { get; set; } = new List<SelectListItem>();

    // الخدمة المختارة حالياً
    public Service? SelectedService { get; set; }

    // البيانات المعقدة للعرض
    public List<ProviderWithServicesViewModel> ProvidersWithServices { get; set; } = new List<ProviderWithServicesViewModel>();
}
