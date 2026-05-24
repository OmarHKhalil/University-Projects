/*
 * ApplicationUserManager - مدير المستخدمين المخصص
 *
 * هذا الكلاس يوسع UserManager الافتراضي في ASP.NET Identity
 * لإضافة منطق أمان إضافي: منع المستخدمين المعطلين من تسجيل الدخول
 *
 * الاستخدام الرئيسي:
 * - يتم استدعاؤه تلقائياً من قبل SignInManager عند محاولة تسجيل الدخول
 * - يتحقق من حالة IsActive قبل التحقق من صحة كلمة المرور
 * - إذا كان المستخدم معطل (!IsActive)، يرفض تسجيل الدخول فوراً
 *
 * هذا يسمح للمشرف بتعطيل حسابات العملاء ومقدمي الخدمات
 * والاحتفاظ بحساباتهم في قاعدة البيانات ولكن منع وصولهم للنظام
 */

using Microsoft.AspNetCore.Identity;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;
using Microsoft.Extensions.Options;
using System;
using System.Threading.Tasks;

namespace mike2.Models
{
    /// <summary>
    /// مدير مستخدمين مخصص يورث من UserManager مع منطق إضافي للتحقق من نشاط المستخدم
    /// TUser محدود بـ ApplicationUser للوصول إلى خاصية IsActive
    /// </summary>
    public class ApplicationUserManager<TUser> : UserManager<TUser> where TUser : ApplicationUser
    {
        /// <summary>
        /// المُنشئ الرئيسي - يستقبل جميع التبعيات المطلوبة لـ ASP.NET Identity
        /// </summary>
        public ApplicationUserManager(
            IUserStore<TUser> store,                    // مخزن المستخدمين (قاعدة البيانات)
            IOptions<IdentityOptions> optionsAccessor,  // خيارات Identity
            IPasswordHasher<TUser> passwordHasher,      // مُجزئ كلمات المرور
            IEnumerable<IUserValidator<TUser>> userValidators,     // مدققو المستخدم
            IEnumerable<IPasswordValidator<TUser>> passwordValidators, // مدققو كلمة المرور
            ILookupNormalizer keyNormalizer,           // مُعياري للبحث (Lowercase)
            IdentityErrorDescriber errors,              // واصف الأخطاء
            IServiceProvider services,                  // حاوي الخدمات
            ILogger<UserManager<TUser>> logger)         // مسجل السجلات
            : base(store, optionsAccessor, passwordHasher, userValidators, passwordValidators, keyNormalizer, errors, services, logger)
        {
        }

        /// <summary>
        /// التحقق من صحة كلمة المرور مع التحقق المسبق من حالة نشاط المستخدم
        ///
        /// هذه الطريقة تُستدعى تلقائياً من قبل SignInManager عند محاولة تسجيل الدخول
        /// الترتيب المنطقي:
        /// 1. التحقق من نشاط المستخدم (IsActive)
        /// 2. إذا نشط: التحقق من كلمة المرور العادية
        /// 3. إذا معطل: رفض فوري بدون الوصول لقاعدة البيانات
        /// </summary>
        /// <param name="user">نموذج المستخدم (ApplicationUser)</param>
        /// <param name="password">كلمة المرور المدخلة</param>
        /// <returns>true إذا صحيحة كلمة المرور والمستخدم نشط، false خلاف ذلك</returns>
        public override async Task<bool> CheckPasswordAsync(TUser user, string password)
        {
            // ================================================
            // 1. التحقق الأمني الأول: حالة نشاط المستخدم
            // ================================================
            // إذا كان المستخدم معطل بواسطة المشرف، نفض تسجيل الدخول فوراً
            // هذا الشرط يمنع المستخدمين المعطلين من الوصول للنظام
            if (!user.IsActive)
            {
                // لا نحتاج للتحقق من كلمة المرور - المستخدم معطل
                return false;
            }

            // ================================================
            // 2. التحقق العادي من كلمة المرور
            // ================================================
            // إذا كان المستخدم نشط، ننفذ التحقق العادي من كلمة المرور
            // يشمل تجزئة كلمة المرور ومقارنتها مع القيمة المخزنة
            return await base.CheckPasswordAsync(user, password);
        }
    }
}
