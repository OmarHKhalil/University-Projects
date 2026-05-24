import 'dart:async';
import 'dart:isolate';
import '../models/activity.dart';
import '../mixins//reminder.dart';

class FitnessService {
  //  خدمة جلب الطقس
  // نستخدم Future لتمثيل عملية ستكتمل في وقت لاحق دون تجميد البرنامج.
  static Future<String> fetchWeatherData() {
    return Future.delayed(Duration(seconds: 2), () => 'Sunny, 25°C');
  }

  //  خدمة حساب السعرات التراكمية
  // تم استخدام async لأن العملية تمر عبر قائمة من الأنشطة وتحتاج وقت معالجة بسيط.
  static Future<double> calculateTotalCalories(List<Activity> activities) async {
    double total = 0;
    for (var activity in activities) {
      // محاكاة تأخير بسيط لكل عملية حسابية لبيان الفرق في الأداء
      await Future.delayed(Duration(milliseconds: 300));
      total += activity.caloriesBurned;
    }
    return total;
  }

  //  خدمة محاكاة عداد الخطوات
  //  نستخدم async* و yield لأن العداد يرسل "سلسلة" من البيانات المستمرة (10، 20، 30...) وليس قيمة واحدة فقط مثل الـ Future.
  static Stream<int> simulateStepCounter() async* {
    int steps = 0;
    while (steps < 100) {
      await Future.delayed(Duration(milliseconds: 500));
      steps += 10;
      // إرسال القيمة الحالية للعداد فور تحديثها
      yield steps;
    }
  }

  // 4. العزل (Isolate): معالجة البيانات في مسار منفصل تماماً (Background Thread).
  // نستخدمه هنا لحساب الإحصائيات الأسبوعية لضمان عدم تأثر سرعة التطبيق الرئيسي
  // أثناء القيام بعمليات حسابية (مثل fold و avg) على قوائم كبيرة.
  static void calculateWeeklyStats(SendPort sendPort) {
    ReceivePort helperPort = ReceivePort();
    // إرسال قناة الاتصال الخاصة بهذا الـ Isolate إلى الـ Main
    sendPort.send(helperPort.sendPort);

    helperPort.listen((message) {
      // استخراج البيانات القادمة من المسار الرئيسي
      List<double> caloriesList = List<double>.from(message['calories']);
      List<int> stepsList = List<int>.from(message['steps']);
      // استخدام دالة fold للقيام بحسابات تراكمية (Functional Programming)
      double totalCal = caloriesList.fold(0, (sum, item) => sum + item);
      int sumSteps = stepsList.fold(0, (sum, item) => sum + item);
      double avgSteps = stepsList.isEmpty ? 0 : sumSteps / stepsList.length;
      // إعادة النتائج النهائية إلى المسار الرئيسي عبر الـ SendPort
      sendPort.send({
        'avgSteps': avgSteps.toStringAsFixed(0),
        'totalCalories': totalCal,
        'activeDays': stepsList.length
      });
      // إغلاق المنفذ بعد انتهاء المهمة
      helperPort.close();
    });
  }
}