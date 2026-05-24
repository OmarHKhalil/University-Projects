import 'workout_plan.dart';
import 'activity.dart';
import '../mixins/reminder.dart';

/// كلاس "الركض" يرث من كلاس النشاط ويستخدم ميزة "التذكير".
class RunningActivity extends Activity with Reminder {
  double distance; // خاصية إضافية تميز الركض عن الأنشطة الأخرى.

  // Constructor يقوم بتمرير البيانات للأب (super) ويهيئ الخصائص الجديدة.
  RunningActivity(int duration, this.distance)
      : super("Running", duration, 0.0){
    // استدعاء دالة الحساب المخصصة للركض
    calculateCalories();
    // تفعيل التذكير الفوري بمجرد إنشاء النشاط.
    sendReminder("Running");
  }

  // داله لحساب السعرات هنا تعتمد على (المدة × المسافة) وليس المدة فقط كالأب.
  @override
  double calculateCalories() {
    // 1. نقوم بالحساب داخلياً
    double result = duration * distance * 1.2;

    // 2. نرسل النتيجة للأب عبر الدالة
    this.caloriesBurned=result;

    return result;
  }
  // إعادة تعريف دالة العرض لإظهار معلومات النشاط.
  @override
  void displayInfo() {
    print(
        "Running - $duration min - $caloriesBurned cal - $distance km");
  }

}