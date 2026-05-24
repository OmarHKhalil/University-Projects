import 'package:flutter/material.dart';

// شاشة الترحيب (لوحة التحكم) الخاصة بنادي فينيزيا الرياضي
class WelcomeScreen extends StatelessWidget {
  const WelcomeScreen({super.key});

  // --- الهوية اللونية للتطبيق ---
  // اللون البرتقالي
  final Color primaryColor = Colors.orangeAccent;
  // اللون الأسود
  final Color secondaryColor = const Color(0xFF1A1A1A);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // تعيين الخلفية البيضاء لتبرز العناصر الملونة فوقها
      backgroundColor: Colors.white,

      // --- الجزء العلوي: الهيدر (Header/AppBar) ---
      appBar: AppBar(
        backgroundColor: secondaryColor, // متناسقة مع الجيم
        elevation: 0, // إلغاء الظل الافتراضي لجعل التصميم مسطحاً (Flat)
        centerTitle: true, // وضع العنوان في المنتصف تماماً
        automaticallyImplyLeading: false, // منع ظهور زر "الرجوع" الافتراضي
        title: const Text(
          'DASHBOARD', // اسم الشاشة الحالية
          style: TextStyle(
            color: Colors.white,
            fontWeight: FontWeight.w900, // خط عريض
            letterSpacing: 2, // تباعد بين الحروف
          ),
        ),
        // قص حواف الهيدر لتكون دائرية من الأسفل فقط
        shape: const RoundedRectangleBorder(
          borderRadius: BorderRadius.vertical(bottom: Radius.circular(25)),
        ),
      ),

      // --- الجزء الأوسط: محتوى الصفحة (Body) ---
      body: Padding(
        padding: const EdgeInsets.all(30.0), // ترك مسافة 30 بكسل من جميع الجهات
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start, // محاذاة العناصر لليسار
          children: [
            // السطر الأول: أيقونة الشمس ونص "صباح الخير"
            Row(
              children: [
                Icon(Icons.wb_sunny_rounded, color: primaryColor, size: 28),
                const SizedBox(width: 10), // مسافة أفقية بين الأيقونة والنص
                const Text(
                  "Good Morning,",
                  style: TextStyle(
                    fontSize: 20,
                    color: Colors.grey, // لون رمادي للنص الثانوي
                    fontWeight: FontWeight.w500,
                  ),
                ),
              ],
            ),
            const SizedBox(height: 10), // مسافة رأسية بسيطة

            // السطر الثاني: نص الترحيب بالمستخدم
            Text(
              "Hello, Omar!",
              style: TextStyle(
                fontSize: 40,
                fontWeight: FontWeight.w900, // خط سميك جداً للتميز
                color: secondaryColor, // اللون الداكن الأساسي
              ),
            ),
          ],
        ),
      ),

      // --- الجزء السفلي: الفوتر (Bottom Navigation Bar) ---
      bottomNavigationBar: Container(
        height: 80, // تحديد ارتفاع ثابت للفوتر
        decoration: BoxDecoration(
          color: secondaryColor,
          // جعل الزوايا العلوية للفوتر دائرية
          borderRadius: const BorderRadius.vertical(top: Radius.circular(30)),
          boxShadow: [
            // إضافة ظل خفيف للأعلى
            BoxShadow(
              color: Colors.black.withOpacity(0.2),
              blurRadius: 10,
              offset: const Offset(0, -2),
            ),
          ],
        ),
        // توزيع أيقونات التنقل في الفوتر
        child: Row(
          mainAxisAlignment: MainAxisAlignment.spaceAround, // توزيع الأيقونات بمسافات متساوية
          children: [
            // استدعاء الدالة المساعدة لبناء كل عنصر في الفوتر
            _buildFooterItem(Icons.home_filled, "Home", true), // العنصر النشط حالياً
            _buildFooterItem(Icons.fitness_center, "Train", false),
            _buildFooterItem(Icons.person_rounded, "Profile", false),
          ],
        ),
      ),
    );
  }

  // دالة مساعدة لبناء عناصر الفوتر
  // [icon]: شكل الأيقونة، [label]: النص أسفلها، [isActive]: هل العنصر مفعل أم لا
  Widget _buildFooterItem(IconData icon, String label, bool isActive) {
    return Column(
      mainAxisAlignment: MainAxisAlignment.center, // توسيط المحتوى داخل العمود
      children: [
        Icon(
          icon,
          // إذا كان العنصر نشطاً يظهر بالبرتقالي، وإذا لم يكن يظهر بالأبيض الشفاف
          color: isActive ? primaryColor : Colors.white54,
          size: 28,
        ),
        const SizedBox(height: 4),
        Text(
          label,
          style: TextStyle(
            color: isActive ? primaryColor : Colors.white54,
            fontSize: 12,
            fontWeight: isActive ? FontWeight.bold : FontWeight.normal,
          ),
        ),
      ],
    );
  }
}