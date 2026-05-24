# 🎯 نظام خدمة الحجوزات المتكامل

## 📖 نظرة عامة على النظام

نظام خدمة حجوزات مبني باستخدام **ASP.NET Core MVC** و **Entity Framework Core** يربط بين العملاء ومقدمي الخدمات. يدعم النظام حجز الخدمات، إدارة المواعيد، النظام الإشعاري، والتقييمات مع لوحة تحكم إدارية كاملة.

## 🛠️ التقنيات المستخدمة

| المكون | التقنية | الوصف |
|---|---|---|
| **الأمامي** | ASP.NET Core MVC | العرض والتحكم والنماذج |
| **الخلفي** | ASP.NET Core | API والمنطق التجاري |
| **قاعدة البيانات** | SQL Server + EF Core | تخزين وحلول LINQ |
| **المصادقة** | ASP.NET Identity | المستخدمين والأدوار |
| **التصميم** | Bootstrap 5 + CSS | واجهة متجاوبة |
| **الأمان** | Identity + HTTPS | مصادقة وحماية |
| **الإشعارات** | Real-time Integration | تحديثات فورية |

## 🗂️ هيكل المشروع

```
📁 mike2/                     # المشروع الرئيسي
├── 📁 Controllers/           # متحكمات MVC
│   ├── AdminController.cs    # لوحة تحكم المشرف
│   ├── BookingsController.cs # إدارة الحجوزات
│   └── ServicesController.cs # إدارة الخدمات
├── 📁 Models/                # نماذج البيانات
│   ├── ApplicationUser.cs    # مستخدم مخصص
│   ├── Booking.cs           # نموذج الحجز
│   └── Service.cs           # نموذج الخدمة
├── 📁 Views/                 # عروض Razor
│   ├── 📁 Admin/            # صفحات المشرف
│   ├── 📁 Bookings/         # صفحات الحجز
│   └── 📁 Shared/           # العناصر المشتركة
├── 📁 Data/                  # الوصول للبيانات
│   ├── ApplicationDbContext.cs # سياق قاعدة البيانات
│   └── SeedData.cs          # البيانات الأولية
├── 📁 Areas/                 # مناطق ASP.NET Identity
├── Program.cs                # نقطة البداية
└── appsettings.json          # إعدادات التكوين
```

---

## 👥 أنواع المستخدمين

### 1. **العميل (Customer)**
- يتصفح الخدمات ومقدميها
- يحجز المواعيد المتاحة
- يقوم بإلغاء أو إعادة جدولة الحجوزات
- يكتب مراجعات للخدمات المكتملة

### 2. **مقدم الخدمة (Service Provider)**
- يضيف ويدير خدماته
- يحدد الأوقات المتاحة
- يقبل/يرفض طلبات الحجز
- يكمل الخدمات ويتلقى تقييمات

### 3. **المشرف (Admin)**
- يدير جميع المستخدمين
- يفعل/يعطل الحسابات
- يشرف على الخدمات والتقييمات
- يرى الإحصائيات والتقارير

---

## 📱 صفحات النظام ووظائفها

### 🏠 **الصفحة الرئيسية**
```
📍 المسار: /
🎯 الوظيفة: عرض الموقع الرئيسي
🏗️ المبني بـ: HomeController.Index()
🎨 المكونات: Navigation Bar + Footer
```

### 🔐 **نظام المصادقة**
```
📍 المسار: /Identity/
🎯 الوظيفة: تسجيل الدخول/الخروج/التسجيل
🏗️ المبني بـ: ASP.NET Identity UI
🎨 المكونات: Login/Register/Logout
```

---

## 🔄 تدفق العميل (Customer Flow)

### 📄 **1. تصفح الخدمات**
```
📍 المسار: /Bookings/CreateForCustomer
🎯 الوظيفة: تصفح الخدمات مع التقييمات
🛠️ التقنية: LINQ GroupBy + Provider Cards
🏗️ البيانات: Services + Reviews + Availabilities
📊 العرض:
├── فلترة حسب الفئة
├── بطاقات مقدمي الخدمات
├── التقييمات تحت كل مقدم
├── عرض الأوقات المتاحة
└── زر "اختر الخدمة"
```

### ⚡ **2. عملية الحجز**
```csharp
// العملية في BookingsController.CreateForCustomer()
1. تحديد الخدمة ← Provider + Service
2. اختيار الوقت ← Availability
3. إنشاء الحجز ← Status: Pending
4. إشعار للمقدم ← New booking request
5. انتظار الموافقة ← Provider decides
```

### ✅ **3. إدارة الحجوزات**
```
📍 المسار: /Bookings/MyBookings
🎯 الوظيفة: عرض حجوزات العميل
🏗️ البيانات: Bookings + Status + Reviews
📊 الحالات:
├── 📅 Pending ← بانتظار موافقة المقدم
├── ✅ Accepted ← تم القبول، جاهز للتنفيذ
├── 🎯 Completed ← انتهت، يمكن كتابة مراجعة
└── ❌ Rejected ← تم الرفض
```

---

## 👨‍🔧 تدفق مقدم الخدمة (Provider Flow)

### ⚙️ **1. لوحة تحكم مقدم الخدمة**
```
📍 المسار: /AppServiceProviders/
🎯 الوظيفة: إدارة ملف مقدم الخدمة
🛠️ العمليات:
├── إنشاء ملف شخصي
├── تحديث المعلومات
├── إضافة الخدمات
└── مراجعة التقييمات
```

### ⏰ **2. إدارة الأوقات المتاحة**
```
📍 المسار: /Availabilities/ProviderAvailabilities
🎯 الوظيفة: إضافة الأوقات المتاحة
🏗️ البيانات: Availabilities جدول
📊 العرض: تقويم بأوقات الخدمة
```

### 📥 **3. إدارة الطلبات**
```
📍 المسار: /Bookings/ProviderBookings
🎯 الوظيفة: مراجعة وقبول/رفض الحجوزات
🛠️ العمليات:
├── ✅ Accept: تغيير Status إلى Accepted
├── ❌ Reject: حذف الحجز + تحرير الوقت
└── 🎯 Complete: الانتهاء وطلب مراجعة
```

---

## 👑 تدفق المشرف (Admin Flow)

### 🖥️ **1. لوحة التحكم الرئيسية**
```
📍 المسار: /Admin/
🎯 الوظيفة: إحصائيات شاملة للنظام
📊 البيانات المعروضة:
├── عدد المستخدمين النشطين
├── عدد الحجوزات اليومية
├── عدد المراجعات المعتمدة
└── مقاييس الأداء العامة
```

### 👥 **2. إدارة المستخدمين**
```
📍 المسار: /Admin/Users
🎯 الوظيفة: التحكم في جميع الحسابات
🛠️ الصلاحيات:
├── عرض جميع المستخدمين
├── تفعيل/تعطيل الحسابات
├── تغيير الأدوار (Customer ↔ Provider)
└── إنشاء مستخدمين جدد
```

### 📊 **3. التقارير والإحصائيات**
```
📍 المسار: /Admin/Reports
🎯 الوظيفة: رؤية شاملة لأداء النظام
📈 المقاييس:
├── إحصائيات الحجوزات
├── أداء مقدمي الخدمات
├── مراجعات المستخدمين
└── اتجاهات الاستخدام
```

---

## 🔔 النظام الإشعاري (Notification System)

### 🎯 **أنواع الإشعارات**

#### **للعملاء:**
```csharp
// 1. تأكيد إرسال الحجز
"Your booking #{id} has been submitted"

// 2. قبول الحجز
"Your booking #{id} has been accepted"

// 3. رفض الحجز
"Your booking #{id} has been rejected"

// 4. انتهاء الخدمة
"Service completed! Please leave a review"
```

#### **للمقدمين:**
```csharp
// 1. طلب حجز جديد
"New booking request from {customer} for {service}"

// 2. إلغاء العميل للحجز
"Booking #{id} was cancelled by customer"
```

### 🔄 **آلية العمل**
```csharp
// في كل عملية حجز (BookingController)
var notification = new Notification {
    UserId = targetUserId,
    BookingId = booking.Id,  // ربط بالحجز
    Message = message,
    IsRead = false,
    CreatedAt = DateTime.Now
};
_context.Notifications.Add(notification);
```

---

## ⭐ نظام التقييمات والمراجعات

### 📊 **التقييمات حسب المقدم**
```csharp
// حساب المتوسط في ServiceProviderController
var reviews = _context.Reviews.Where(r => r.ServiceProviderId == provider.Id);
provider.Rating = (float)reviews.Average(r => r.Rating);
```

### 📝 **كتابة المراجعات**
```
📍 الصفحة: /Bookings/CreateReview/{bookingId}
🎯 الشروط:
├── الحجز يجب أن تكون Completed
├── العميل صاحب الحجز فقط
├── مراجعة واحدة لكل حجز
🎨 النموذج:
├── نجمات التقييم (1-5)
├── نص المراجعة
└── زر الإرسال
```

### 👀 **عرض المراجعات**
```csharp
// في CreateForCustomer - عرض تحت مقدم الخدمة
var recentReviews = provider.Reviews
    .Where(r => r.IsVisible)
    .OrderByDescending(r => r.CreatedAt)
    .Take(3); // آخذ 3 مراجعات حديثة
```

---

## 💾 قاعدة البيانات والعلاقات

### 📊 **الجداول الرئيسية**

```sql
-- مستخدمي النظام
Users (ASP.NET Identity)
├── Id (PK)
├── UserName, Email
├── Role (Customer/Provider/Admin)
└── IsActive (إمكانية الدخول)

-- مقدمي الخدمات
AppServiceProviders
├── Id (PK)
├── UserId (FK → Users)
├── Experience, Rating
└── Specializations

-- الخدمات المعروضة
Services
├── Id (PK)
├── ServiceProviderId (FK)
├── Name, Category
├── Description, BasePrice
└── IsActive

-- الأوقات المتاحة
Availabilities
├── Id (PK)
├── ServiceProviderId (FK)
├── AvailableDate, StartTime, EndTime
└── IsBooked (حالة الحجز)

-- الحجوزات
Bookings
├── Id (PK)
├── CustomerId (FK → Users)
├── ServiceProviderId (FK)
├── ServiceId (FK)
├── AvailabilityId (FK|nullable)
├── Status (Pending/Accepted/Completed/Rejected)
└── BookingDate

-- الإشعارات
Notifications
├── Id (PK)
├── UserId (FK)
├── BookingId (FK|nullable)
├── Message, IsRead
└── CreatedAt

-- المراجعات
Reviews
├── Id (PK)
├── BookingId (FK → unique)
├── ReviewerId (FK → Users)
├── ServiceProviderId (FK)
├── Rating (1-5), Comment
└── IsVisible (اقرار المشرف)
```

### 🔗 **العلاقات (Foreign Keys)**

```
Users (المستخدمون)
├── 1:1 → AppServiceProviders (الملف الشخصي)
├── 1:N → Bookings (كعميل)
├── 1:N → Reviews (ككاتب مراجعة)
└── 1:N → Notifications (الإشعارات)

AppServiceProviders (مقدمي الخدمات)
├── 1:1 ← Users (المستخدم)
├── 1:N → Services (الخدمات المعروضة)
├── 1:N → Availabilities (الأوقات المتاحة)
├── 1:N → Bookings (الحجوزات المستلمة)
└── 1:N → Reviews (المراجعات المكتوبة)

Availabilities ← 0:1 → Bookings (ربط اختياري بالحجوزات)

Bookings ← 1:1 → Reviews (مراجعة واحدة لكل حجز مكتمل)
```

---

## 🚀 تشغيل النظام

### ⚙️ **متطلبات التشغيل**
```
✅ .NET 10.0 SDK
✅ SQL Server (LocalDB أو SQL Server Express)
✅ IIS Express أو Kestrel
✅ متصفح حديث (Chrome/Firefox)
```

### 🏃‍♂️ **خطوات التشغيل**

```bash
# 1. استنساخ المشروع
git clone https://github.com/your-repo/mike2.git
cd mike2

# 2. تثبيت التبعيات
dotnet restore

# 3. تشغيل Migrations (إنشاء قاعدة البيانات)
dotnet ef database update

# 4. تشغيل التطبيق
dotnet run
# أو من Visual Studio: F5

# 5. الوصول للتطبيق
http://localhost:5000
```

### 🔑 **بيانات الدخول التجريبية**

```bash
# المشرف (Admin)
📧 admin@demo.com
🔑 Admin123!

# عميل تجريبي
📧 customer1@demo.com
🔑 Customer123!

# مقدم خدمة تجريبي
📧 cleaner1@demo.com
🔑 Provider123!
```

---

## 🧪 اختبار النظام

### ✅ **اختبارات الحجز الكاملة**

```bash
# 1. تسجيل الدخول كعميل
# 2. تصفح الخدمات → اختيار خدمة
# 3. مراجعة التقييمات تحت مقدم الخدمة
# 4. اختيار وقت متاح
# 5. تأكيد الحجز

# 6. تسجيل الخروج
# 7. تسجيل الدخول كمقدم خدمة
# 8. مراجعة طلبات الحجز
# 9. قبول الطلب
# 10. إكمال الخدمة

# 11. تسجيل الدخول كعميل مرة أخرى
# 12. كتابة مراجعة للخدمة المكتملة
```

### 🛠️ **اختبار وظائف المشرف**

```bash
# 1. تسجيل الدخول كـ admin
# 2. مراجعة لوحة التحكم (إحصائيات)
# 3. إدارة المستخدمين (تفعيل/تعطيل)
# 4. مراجعة المراجعات والخدمات
# 5. عرض التقارير والإحصائيات
```

---

## 🔧 استكشاف الأخطاء

### 🚫 **مشاكل شائعة وحلولها**

#### **خطأ في قاعدة البيانات**
```
Error: Cannot find connection string 'DefaultConnection'
```
```json
// في appsettings.json - تأكد من صحة السلسلة
"ConnectionStrings": {
  "DefaultConnection": "Server=(localdb)\\MSSQLLocalDB;Database=mike2;Trusted_Connection=True;"
}
```

#### **مشاكل في تسجيل الدخول**
```
Error: User is disabled
```
```
// تحقق من جدول Users.IsActive = true
// أو قم بتفعيل الحساب من /Admin/Users
```

#### **مشاكل في Entity Framework**
```bash
# حذف وإعادة إنشاء قاعدة البيانات
dotnet ef database drop
dotnet ef migrations remove
dotnet ef migrations add InitialCreate
dotnet ef database update
```

---

## 🏗️ تطوير النظام

### 🆕 **إضافة ميزة جديدة**

```csharp
// 1. إضافة Model جديد
public class NewFeature {
    public int Id { get; set; }
    public string Name { get; set; }
}

// 2. إضافة DbSet في ApplicationDbContext
public DbSet<NewFeature> NewFeatures { get; set; }

// 3. إنشاء Migration
dotnet ef migrations add AddNewFeature

// 4. إضافة Controller
public class NewFeaturesController : Controller {
    // CRUD operations
}

// 5. إضافة Views في مجلد NewFeatures/
// 6. إضافة روابط في _Layout.cshtml
```

### 📊 **تحسين الأداء**

```csharp
// استخدم AsNoTracking للقراءة فقط
var services = await _context.Services.AsNoTracking().ToListAsync();

// Split Query للعلاقات الكبيرة
var bookings = await _context.Bookings
    .Include(b => b.Service)
    .AsSplitQuery()
    .ToListAsync();

// احذف البيانات الزائدة تلقائياً
_context.ChangeTracker.AutoDetectChangesEnabled = false;
```

---

## 📞 الدعم والمساعدة

### 💡 **للأسئلة التقنية:**

🔸 **ASP.NET Core MVC**: أسس بناء تطبيقات الويب
🔸 **Entity Framework Core**: التعامل مع قواعد البيانات
🔸 **ASP.NET Identity**: نظام المستخدمين والمصادقة
🔸 **Bootstrap**: تصميم واجهات الويب المتجاوبة

### 📋 **أفضل الممارسات:**

- ✅ استخدم Dependency Injection دائماً
- ✅ طبق مبدأ Single Responsibility
- ✅ اكتب Unit Tests للوظائف criticoal
- ✅ استخدم Async/Await للعمليات I/O
- ✅ طبق Validation على جميع المدخلات

---

## 🎉 ختام

هذا النظام يمثل منصة شاملة لحجز الخدمات مع جميع الميزات المطلوبة:
- 🔐 **أمان شامل** مع إدارة المستخدمين
- 📅 **إدارة حجوزات ذكية** مع نظام القبول/رفض
- ⭐ **تقييمات تفاعلية** لضمان الجودة
- 📊 **لوحة إدارة قوية** للمشرف
- 🎨 **تصميم متجاوب** يعمل على جميع الأجهزة

النظام جاهز للاستخدام والتطوير! 🚀✨
