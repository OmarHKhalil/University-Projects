// كلاس استثناء مخصص لمعالجة أخطاء البيانات في التمارين
// نستخدم "implements Exception" لجعله جزءاً من نظام معالجة الأخطاء في Dart
class InvalidWorkoutDataException implements Exception {
  final String message; // رسالة توضح طبيعة الخطأ (مثل: الوقت يجب أن يكون موجباً)
  final String field;   // اسم الحقل الذي وقع فيه الخطأ (مثل: duration أو weight)

  // Constructor لاستقبال تفاصيل الخطأ عند حدوثه
  InvalidWorkoutDataException(this.message, this.field);

  // إعادة كتابة دالة toString لتنسيق طريقة ظهور الخطأ للمستخدم
  @override
  String toString() {
    return "Error in $field: $message";
  }
}