import 'package:flutter/material.dart';
import 'welcome.dart'; // استيراد صفحة الترحيب للانتقال إليها بعد المصادقة

/// شاشة تسجيل الدخول الرئيسية لنادي فينيزيا الرياضي
class LoginScreen extends StatefulWidget {
  const LoginScreen({super.key});

  @override
  State<LoginScreen> createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  // --- إعدادات الهوية البصرية ---
  final Color primaryColor = Colors.orangeAccent; // اللون البرتقالي للتنبيه والنشاط
  final Color secondaryColor = const Color(0xFF1A1A1A); // اللون الأسود
  // const Color(0xFF0D1B2A);const Color(0xFF2B2D42);const Color(0xFF1B4332)
  // دالة للانتقال إلى شاشة الترحيب عند الضغط على زر الدخول
  void _loginPressed() {
    Navigator.of(context).push(
      MaterialPageRoute(builder: (context) => const WelcomeScreen()),
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      // تجنب حدوث خطأ Overflow عند ظهور لوحة المفاتيح
      resizeToAvoidBottomInset: true,
      backgroundColor: Colors.white,

      // --- شريط التطبيق العلوي ---
      appBar: AppBar(
        backgroundColor: secondaryColor,
        elevation: 0,
        centerTitle: true,
        title: const Text(
          'VENEZIA GYM',
          style: TextStyle(
            color: Colors.white,
            fontWeight: FontWeight.w900, // سمك الخط
            fontSize: 24,
            letterSpacing: 2, // تباعد الحروف
          ),
        ),
        // تصميم حواف منحنية لشريط التطبيق
        shape: const RoundedRectangleBorder(
          borderRadius: BorderRadius.vertical(bottom: Radius.circular(25)),
        ),
      ),

      // استخدام SingleChildScrollView لدعم الشاشات الصغيرة والتمرير
      body: SingleChildScrollView(
        child: Column(
          children: [
            const SizedBox(height: 80), // مساحة علوية لإفساح المجال للشعار الدائري
            Center(
              child: ConstrainedBox(
                constraints: const BoxConstraints(maxWidth: 420), // لضمان عدم تمدد الواجهة بشكل مفرط على التابلت
                child: Stack(
                  clipBehavior: Clip.none, // للسماح للشعار بالبروز خارج حدود الحاوية (Positioned)
                  children: [
                    // --- البطاقة البيضاء (Card) التي تحتوي على الحقول ---
                    Container(
                      margin: const EdgeInsets.symmetric(horizontal: 20),
                      decoration: BoxDecoration(
                        color: Colors.white,
                        borderRadius: BorderRadius.circular(30),
                        boxShadow: [
                          BoxShadow(
                            color: Colors.black.withOpacity(0.1),
                            blurRadius: 30,
                            spreadRadius: 5,
                          ),
                        ],
                      ),
                      child: Padding(
                        padding: const EdgeInsets.symmetric(horizontal: 25, vertical: 50),
                        child: Column(
                          mainAxisSize: MainAxisSize.min,
                          children: [
                            const SizedBox(height: 40),

                            // نص ترحيبي بأسلوب RichText لدمج ألوان مختلفة
                            RichText(
                              textAlign: TextAlign.center,
                              text: TextSpan(
                                style: const TextStyle(fontSize: 16, color: Colors.black54, height: 1.5),
                                children: [
                                  const TextSpan(text: 'READY TO '),
                                  TextSpan(
                                      text: 'TRAIN? ',
                                      style: TextStyle(color: primaryColor, fontWeight: FontWeight.w900, fontSize: 18)
                                  ),
                                  const TextSpan(text: '\nEnter your member ID and password.'),
                                ],
                              ),
                            ),
                            const SizedBox(height: 35),

                            // --- حقل إدخال رقم العضوية ---
                            TextField(
                              decoration: InputDecoration(
                                labelText: 'Member ID',
                                prefixIcon: Icon(Icons.badge_outlined, color: primaryColor),
                                border: OutlineInputBorder(borderRadius: BorderRadius.circular(15)),
                                focusedBorder: OutlineInputBorder(
                                  borderRadius: BorderRadius.circular(15),
                                  borderSide: BorderSide(color: primaryColor, width: 2),
                                ),
                              ),
                              keyboardType: TextInputType.number,
                            ),
                            const SizedBox(height: 20),

                            // --- حقل إدخال كلمة المرور ---
                            TextField(
                              obscureText: true, // لإخفاء الحروف أثناء الكتابة
                              decoration: InputDecoration(
                                labelText: 'Password',
                                prefixIcon: Icon(Icons.lock_person_outlined, color: primaryColor),
                                border: OutlineInputBorder(borderRadius: BorderRadius.circular(15)),
                                focusedBorder: OutlineInputBorder(
                                  borderRadius: BorderRadius.circular(15),
                                  borderSide: BorderSide(color: primaryColor, width: 2),
                                ),
                              ),
                            ),
                            const SizedBox(height: 35),

                            // --- زر البدء (START WORKOUT) ---
                            SizedBox(
                              width: double.infinity,
                              height: 55,
                              child: ElevatedButton(
                                style: ElevatedButton.styleFrom(
                                  backgroundColor: secondaryColor,
                                  foregroundColor: Colors.white,
                                  shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(15)),
                                  elevation: 5,
                                ),
                                onPressed: _loginPressed,
                                child: const Text('START WORKOUT', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold)),
                              ),
                            ),
                            const SizedBox(height: 15),

                            // زر نصي لطلب العضوية
                            TextButton(
                              onPressed: () {},
                              child: Text(
                                'Become a Member',
                                style: TextStyle(color: primaryColor, fontWeight: FontWeight.bold, decoration: TextDecoration.underline),
                              ),
                            ),
                          ],
                        ),
                      ),
                    ),

                    // --- شعار النادي (الأثقال) يوضع فوق البطاقة ---
                    Positioned(
                      top: -60, // رفع نصف الدائرة خارج الحاوية البيضاء
                      left: 0,
                      right: 0,
                      child: Center(
                        child: Container(
                          width: 120,
                          height: 120,
                          decoration: BoxDecoration(
                            color: Colors.white,
                            shape: BoxShape.circle,
                            boxShadow: [
                              BoxShadow(color: primaryColor.withOpacity(0.4), blurRadius: 25, spreadRadius: 5)
                            ],
                            border: Border.all(color: secondaryColor, width: 4), // إطار أسود حول الشعار
                          ),
                          child: Icon(Icons.fitness_center_rounded, size: 60, color: secondaryColor),
                        ),
                      ),
                    ),
                  ],
                ),
              ),
            ),

            // --- تذييل الصفحة التحفيزي ---
            const SizedBox(height: 50),
            Padding(
              padding: const EdgeInsets.symmetric(horizontal: 40),
              child: Column(
                children: [
                  Icon(Icons.bolt, color: primaryColor, size: 30), // أيقونة الصاعقة للتحفيز
                  const SizedBox(height: 10),
                  const Text(
                    'No Excuses. Only Results.',
                    textAlign: TextAlign.center,
                    style: TextStyle(
                      fontStyle: FontStyle.italic,
                      fontWeight: FontWeight.w600,
                      color: Colors.black45,
                    ),
                  ),
                ],
              ),
            ),
            const SizedBox(height: 20),
          ],
        ),
      ),
    );
  }
}