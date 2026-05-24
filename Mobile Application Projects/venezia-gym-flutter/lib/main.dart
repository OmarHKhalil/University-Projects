import 'package:flutter/material.dart'; // استيراد مكتبة Material Design التي تحتوي على جميع العناصر الواجهة (Buttons, Text, etc.)
import 'login.dart'; // استيراد ملف صفحة الدخول

// بدا تنفيذ الكود من هنا
void main() {
  runApp(const MyApp()); // تشغيل التطبيق وبناء الودجيت
}

// كلاس MyApp هو الاساس للتطبيق، ونستخدم StatelessWidget لأنه لا يحتاج لتغيير حالته داخلياً
class MyApp extends StatelessWidget {
  const MyApp({super.key}); // الكونستراكتور لتعريف المعرف الفريد للكلاس

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      // اخفاء الشريط الاحمر
      debugShowCheckedModeBanner: false,
      title: 'Venezia App', // اسم التطبيق
      // إعدادات الألوان والشكل العام للتطبيق
      theme: ThemeData(
        primarySwatch: Colors.blue, // اللون الأساسي للتطبيق
        useMaterial3: true,
      ),
      // الشاشة التي تظهر للمستخدم عند فتح التطبيق
      home: const LoginScreen(),
    );
  }
}