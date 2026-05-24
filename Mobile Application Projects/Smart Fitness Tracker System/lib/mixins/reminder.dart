// تعريف Mixin هو وسيلة لإعادة استخدام الكود في فئات (Classes) متعددة دون الحاجة للوراثة الكاملة.
mixin Reminder {
  // دالة لإرسال تذكير ببدء التمرين
  void sendReminder(String exercise) {
    print("Reminder: It's time for your $exercise session! Stay fit!");
  }

  // إضافة دالة للتهنئة عند الوصول لهدف معين
  void notifyGoalReached(int steps) {
    print("CONGRATULATIONS! You've reached your goal of $steps steps! Keep it up! 🎊");
  }
}