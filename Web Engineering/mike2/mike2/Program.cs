/*
 * ملف إعداد التطبيق الرئيسي (ASP.NET Core Application Startup)
 *
 * هذا الملف يقوم بإعداد جميع الخدمات والمكونات الأساسية لتطبيق خدمة الحجوزات
 * باستخدام تقنيات ASP.NET Core، Entity Framework، و ASP.NET Identity
 *
 * التقنيات المستخدمة:
 * - ASP.NET Core MVC: للعرض والتحكم والنماذج
 * - Entity Framework Core: لإدارة قاعدة البيانات (Database ORM)
 * - ASP.NET Identity: لإدارة المستخدمين و المصادقة
 * - SQL Server: قاعدة البيانات
 * - Bootstrap: للتصميم الأمامي
 */

using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using mike2.Data;
using mike2.Models;   // مهم: لاستخدام نموذج المستخدم المخصص ApplicationUser

// إعداد WebApplicationBuilder للتطبيق
var builder = WebApplication.CreateBuilder(args);

// ========================================
// 1. إعداد قاعدة البيانات (Database Configuration)
// ========================================
// استرجاع سلسلة الاتصال من appsettings.json
var connectionString = builder.Configuration.GetConnectionString("DefaultConnection")
    ?? throw new InvalidOperationException("Connection string 'DefaultConnection' not found.");

// تسجيل ApplicationDbContext مع SQL Server - هذا السياق يحتوي على جميع النماذج والجداول
builder.Services.AddDbContext<ApplicationDbContext>(options =>
    options.UseSqlServer(connectionString));

// إضافة صفحة مطور قاعدة البيانات للتطوير فقط
builder.Services.AddDatabaseDeveloperPageExceptionFilter();

// ========================================
// 2. إعداد المصادقة والمستخدمين (Authentication & User Management)
// ========================================
// تسجيل ApplicationUserManager المخصص للتحقق من حالة نشاط المستخدم
builder.Services.AddScoped<UserManager<ApplicationUser>, ApplicationUserManager<ApplicationUser>>();

// إعداد ASP.NET Identity مع ApplicationUser (نموذج مخصص) بدلا من IdentityUser العادي
// هذا يسمح بإضافة حقول إضافية مثل FullName, Role, IsActive, Location
builder.Services
    .AddDefaultIdentity<ApplicationUser>(options =>
    {
        options.SignIn.RequireConfirmedAccount = false; // لا نطلب تأكيد البريد الإلكتروني للسهولة
    })
    .AddRoles<IdentityRole>()                           // دعم الأدوار (Admin, Customer, ServiceProvider)
    .AddEntityFrameworkStores<ApplicationDbContext>()  // استخدام EF مع قاعدة البيانات
    .AddUserManager<ApplicationUserManager<ApplicationUser>>(); // استخدام UserManager المخصص

// ========================================
// 3. إعداد MVC والعرض (MVC & Views Setup)
// ========================================
// إضافة خدمات MVC مع دعم العروض (Views) والعناصر الجزئية
builder.Services.AddControllersWithViews();

// إضافة دعم صفحات Razor (ضروري لـ ASP.NET Identity UI مثل تسجيل الدخول/الخروج)
builder.Services.AddRazorPages();

// ========================================
// 4. بناء وتشغيل التطبيق (Build & Run Application)
// ========================================
// بناء التطبيق مع جميع الخدمات المسجلة أعلاه
var app = builder.Build();

// ========================================
// 5. تهيئة البيانات الأولية (Data Seeding) - يتم عند كل تشغيل
// ========================================
// إنشاء نطاق خدمات جديد للوصول إلى قاعدة البيانات وإجراء التهيئة
using (var scope = app.Services.CreateScope())
{
    var services = scope.ServiceProvider;
    // استدعاء SeedData.InitializeAsync لإنشاء الأدوار، المشرف الافتراضي، وحذف الحجوزات المرفوضة
    await SeedData.InitializeAsync(services);
}

// ========================================
// 6. pipeline معالجة الطلبات (Request Processing Pipeline)
// ========================================
// للتطوير: استخدم صفحة أخطاء قاعدة البيانات وأدوات التطوير
if (app.Environment.IsDevelopment())
{
    app.UseMigrationsEndPoint(); // صفحة لإدارة migrations EF Core
}
else
{
    // للإنتاج: صفحة خطأ عامة وحماية HTTPS المعززة
    app.UseExceptionHandler("/Home/Error");
    app.UseHsts(); // HTTP Strict Transport Security
}

// استخدام HTTPS دائماً
app.UseHttpsRedirection();

// تفعيل نظام التوجيه (Routing)
app.UseRouting();

// ترتيب مهم: المصادقة (Authentication) قبل التفويض (Authorization)
app.UseAuthentication(); // التحقق من هوية المستخدم
app.UseAuthorization();  // التحقق من صلاحيات المستخدم

// دعم الملفات الثابتة (CSS, JS, Images)
app.MapStaticAssets();

// ========================================
// 7. إعداد المسارات (Routing Configuration)
// ========================================
// مسار MVC الرئيسي للتطبيق - يتوجه الطلبات إلى Controllers
app.MapControllerRoute(
        name: "default",
        pattern: "{controller=Home}/{action=Index}/{id?}")
   .WithStaticAssets();

// مسار صفحات Razor (لـ ASP.NET Identity UI مثل تسجيل الدخول/الخروج)
app.MapRazorPages()
   .WithStaticAssets();

// تشغيل التطبيق وانتظار الطلبات
app.Run();
