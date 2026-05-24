import '../utils/SportsCalculator.dart';
import 'workout_plan.dart';

abstract class CalorieCalculator {
  double calculateCalories();
}

class Activity implements CalorieCalculator {
  // تغليف البيانات (Encapsulation) استخدام الرموز الخاصة (_) لحماية البيانات.
  String _type;
  int _duration;
  double _caloriesBurned = 0;
  // استخدام late لأن الخطة يتم تحديدها لاحقاً بناءً على نوع النشاط.
  late WorkoutPlan plan;

  // Constructor يقوم بتهيئة البيانات وتشغيل الحسابات تلقائياً
  Activity(this._type, this._duration, this._caloriesBurned){
    calculateCalories();
    this.plan = WorkoutPlan.getPlanFor(type);
  }

  // Named Constructor يوفر مرونة لإنشاء كائن عام ببيانات افتراضية
  Activity.withDefaults()
      : _type = "General Workout",
        _duration = 30,
        _caloriesBurned = 200;

  // Getters
  String get type => _type;
  int get duration => _duration;
  double get caloriesBurned => _caloriesBurned;

  // Setters
  set duration(int value) {
    if (value > 0) _duration = value;
  }

  set caloriesBurned(double value) {
    if (value >= 0) _caloriesBurned = value;
  }

  // Polymorphism دالة الحساب الافتراضية.
  double calculateCalories() {
    //حساب السعرات بناءً على المده
    double result = _duration * 25.0;

    // استخدام الـ Setter لتحديث القيمة
    this.caloriesBurned=result;

    return result;
  }

  // دالة لعرض تفاصيل النشاط
  void displayInfo() {
    print("$type - $duration min - $caloriesBurned cal");
  }
}