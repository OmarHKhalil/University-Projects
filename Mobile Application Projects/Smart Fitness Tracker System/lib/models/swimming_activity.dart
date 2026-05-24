import 'activity.dart';
import 'workout_plan.dart';

// كلاس السباحة يرث من الكلاس الأساسي Activity.
class SwimmingActivity extends Activity {
  int laps;

  // الـ Constructor الخاص بالسباحة.
  SwimmingActivity( int duration, this.laps)
      : super("Swimming", duration, 0.0){
    calculateCalories();

  }
  // إعادة تعريف دالة حساب السعرات (Polymorphism).
  @override
  double calculateCalories() {
    //  حساب السعرات بناءً على الأشواط
    double result = laps * 25.0;

    // 2. تحديث المتغير الخاص في الأب باستخدام الـ Setter
    this.caloriesBurned=result;

    return result;
  }
  // إعادة تعريف دالة العرض لطباعه معلومات السباحة
  @override
  void displayInfo() {
    print(
        "Swimming - $duration min - $caloriesBurned cal - $laps laps");
  }
}