using System.Collections.Generic;
using System.Linq;
using mike2.Models;

namespace mike2.ViewModel
{
    public class ProviderDashboardViewModel
    {
        public AppServiceProvider Provider { get; set; }

        // قائمة الخدمات لمقدم الخدمة
        public IEnumerable<Service> Services { get; set; }

        public IEnumerable<Availability> Availabilities { get; set; }
        public IEnumerable<Booking> NewBookings { get; set; }
        public IEnumerable<Booking> HistoryBookings { get; set; }
        public IEnumerable<Notification> Notifications { get; set; }

        // عدد الإشعارات غير المقروءة (أنت تملأه في الـ Controller)
        public int UnreadNotificationsCount { get; set; }

        // خاصية محسوبة لعرض عدد الخدمات في الـ Dashboard
        public int ServicesCount => Services?.Count() ?? 0;
    }
}
