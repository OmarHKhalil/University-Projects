class SportsCalculator {
  //  حساب الـ BMI
  static double calculateBMI(double weight, double height) {
    if (height <= 0) return 0;
    return weight / ((height / 100) * (height / 100));
  }

  //  تحديد تصنيف الـ BMI
  static String getBMICategory(double bmi) {
    if (bmi < 18.5) return "Underweight";
    if (bmi <= 24.9) return "Normal weight";
    if (bmi <= 29.9) return "Overweight";
    return "Obese";
  }

  //  تحديد فئة العمر باستخدام switch
  static String getAgeCategory(int age) {
    switch (age) {
      case < 18: return "Youth";
      case >= 18 && <= 35: return "Young Adult";
      case >= 36 && <= 50: return "Adult";
      case >= 51: return "Senior";
      default: return "Unknown";
    }
  }

  //  حساب مجموع الخطوات
  static int calculateTotalSteps(Iterable<int> steps) {
    int total = 0; // متغير لتخزين المجموع الابتدائي

    // استخدام for in للمرور على كل عنصر في القائمة
    for (int step in steps) {
      total += step;
    }

    return total; // إرجاع النتيجة النهائية
  }
}