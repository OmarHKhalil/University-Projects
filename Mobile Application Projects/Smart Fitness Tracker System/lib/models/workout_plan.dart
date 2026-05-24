// كلاس يمثل خطة التمرين (إحماء وتبريد).
class WorkoutPlan {
  final String warmup;
  final String cooldown;

  // Constructor
  const WorkoutPlan(this.warmup, this.cooldown);

  // تابع (Function) داخل الكلاس يعطي خطة مخصصة لكل نوع
  static WorkoutPlan getPlanFor(String activityType) {
    if (activityType == "Running") {
      return const WorkoutPlan(
          "Warmup: 5 mins leg stretching",
          "Cooldown: 5 mins slow walking"
      );

    } else if (activityType == "Swimming") {
      return const WorkoutPlan(
          "Warmup: 3 mins shoulder rotation",
          "Cooldown: 2 mins floating"
      );
    } else {
      return const WorkoutPlan("General Warmup", "General Cooldown");
    }
  }
}