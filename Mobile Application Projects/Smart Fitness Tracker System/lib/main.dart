import 'dart:io';
import 'dart:isolate';
import 'dart:async';

// استيراد الملفات الأخرى
import 'models/activity.dart';
import 'models/running_activity.dart';
import 'models/swimming_activity.dart';
import 'models/workout_plan.dart';
import 'exceptions/invalid_workout_exception.dart';
import 'utils/fitness_service.dart';
import 'utils/SportsCalculator.dart';
// 1. إنشاء القائمة الابتدائية
var list1 = [Activity('Yoga', 30, 0)];
var list2 = [Activity('Yoga', 45, 0)];
// دمج القائمتين وتخزين النتيجة في list
List<Activity> list = [...list1, ...list2];

// 2. Set لتخزين ما مارسه المستخدم
Set<String> practicedTypes = {};

Map<String, int> dailySteps = {
  "2023-10-01": 5000,
  "2023-10-02": 8500,
  "2023-10-03": 10000,
  "2023-10-04": 7200,
  "2023-10-05": 6000,
};

// 2. دالة تشغيل البرنامج الرئيسية
void main() async {
  print("========================================");
  print("   🏃 AIU FITNESS TRACKER SYSTEM 🏃   ");
  print("========================================\n");
  print(list);
  try {
    // إدخال البيانات المستخدم وحساب BMI
    var userProfile = userInput();
    displayUserInfo(userProfile);
    print("-(:-(:-(:-(:-(:-(:-(:-(:");
    // --- الجزء الثاني والثالث: الأنشطة والمجموعات ---
    List<Activity> activities = setupActivities();
    managementActivities(activities);
    print("-(:-(:-(:-(:-(:-(:-(:-(:");
    // --- الجزء الرابع: المجموعات (Set & Map) ---
    handleCollectionsDemo();
    print("-(:-(:-(:-(:-(:-(:-(:-(:");
    manageDailySteps(dailySteps);
    print("-(:-(:-(:-(:-(:-(:-(:-(:");
    //  المحاكاة (Async: Future, Stream, Isolate)
    // الـ await هنا تضمن ترتيب ظهور النتائج
    await _runSimulations();
    print("-(:-(:-(:-(:-(:-(:-(:-(:");
  } catch (e) {
    print("\n⚠️ System Note: $e");
  } finally {
    print("\n========================================");
    print("✅ All operations completed successfully.");
    print("========================================");
  }
}

// ---------------------------------------------------------
// 3. الدوال الفرعية لتنظيم الكود (Helper Methods)
// ---------------------------------------------------------

Map<String, dynamic> userInput() {
  String name;
  int age, dailyStep;
  double weight, height;

  try {
    print("\n--- Please enter your information ---");

    stdout.write("Enter your name: ");
    name = stdin.readLineSync() ?? "";
    if (name.trim().isEmpty || RegExp(r'[0-9]').hasMatch(name)) {
      print("Error: Name cannot be empty or contain numbers.");
      return userInput(); // إعادة المحاولة
    }

    stdout.write("Enter your age: ");
    age = int.parse(stdin.readLineSync() ?? "");

    stdout.write("Enter weight (kg): ");
    weight = double.parse(stdin.readLineSync() ?? "");

    stdout.write("Enter height (cm): ");
    height = double.parse(stdin.readLineSync() ?? "");

    // التحقق من المنطق الرياضي للبيانات (يجب أن تكون موجبة)
    if (age <= 0 || weight <= 0 || height <= 0) {
      print("Logic Error: Age, Weight, and Height must be realistic positive numbers.");
      return userInput();
    }

    stdout.write("Enter Daily Step Goal: ");
    dailyStep = int.parse(stdin.readLineSync() ?? "");

    stdout.write("Enter Health Condition (Optional): ");
    String healthCondition = stdin.readLineSync() ?? "None";

    return {
      'name': name,
      'age': age,
      'w': weight,
      'h': height,
      'dailyStep': dailyStep,
      'healthCondition': healthCondition
    };

  } on FormatException {
    // في حال أدخل نصاً بدلاً من رقم
    print("\nInput Error: Please enter digits only (Numbers) for age, weight, and height.");
    return userInput();
  } catch (e) {
    // لأي خطأ غير متوقع آخر
    print("\nUnexpected error: $e");
    return userInput();
  }
}

void displayUserInfo(Map<String, dynamic> user) {
  // استدعاء الدوال الحسابيه من كلاس مع تمرير المعلومات المستخرجة من SportsCalculator التي عباها المستخدم
  double bmi = SportsCalculator.calculateBMI(user['w'], user['h']);
  String category = SportsCalculator.getBMICategory(bmi);
  String ageCategory = SportsCalculator.getAgeCategory(user['age']);

  print("\nBMI: ${bmi.toStringAsFixed(2)} ($category)");
  print("Age Category: $ageCategory\n");

  print("--- Weekly Step Goals ---");
  for (int day = 1; day <= 5; day++) {
    print("Day $day: ${user['dailyStep']} steps");
  }
}

List<Activity> setupActivities() {
  //  إضافة 3 أنشطة على الأقل
  processWorkoutData('Walking', 20, 100);
  processWorkoutData("Cycling",40, 8);
  processWorkoutData('Yoga', 15, 50);
  try {
    processWorkoutData("Running", 30, 5.0);
    processWorkoutData("Walking", 15, 0.0);
    processWorkoutData("Swimming", -5, 10.0); // خطأ لتجربة الـ Exception

  } on InvalidWorkoutDataException catch (e) {// معالجة الاستثناء المخصص
    print("Caught in Main: ${e.toString()}");
  } finally {
    print("Total activities: ${list.length}");
    print("Operation attempted.");
  }
  return list;
}

void managementActivities(List<Activity> activities) {
  print("\n--- Final Activities List ---");

  // طباعة جميع الأنشطة باستخدام
  for (var act in activities) {
    // استدعاء داله الطباعه الخاصه بكل كلاس
    act.displayInfo();
    print("-----------------------");
  }
}

// داله تجعل المستخدم يختار التمارين التي مارسها
void handleCollectionsDemo() {
  print("--- Exercise Logging System ---");
  print("Available activities in the system are: ${list.map((e) => e.type).toList()}");
  while (true) {
    stdout.write("\n Enter an activity you did (or type 'exit' to finish):");
    String input = stdin.readLineSync() ?? "";

    if (input.toLowerCase() == 'exit') break;

    // التحقق من النشاط الذي أدخله المستخدم موجود في قائمة النظام
    bool isRegistered = list.any((act) => act.type.toLowerCase() == input.toLowerCase());

    if (isRegistered) {
      practicedTypes.add(input); // اذا كان موجود يضيفه لل Set
      print("✅ '$input' was successfully logged.");
     } else {
      // اذا كان غير موجود يطبع رساله خطا
      print("⚠️ Warning: '$input' activity is not listed in the system (not performed by the user according to the records).");
    }
  }

  print("\n--- Summary of Unique Activities Actually Performed ---");
  if (practicedTypes.isEmpty) {
    // اذا لم يختار المستخدم اي نشاط يتم طباعه رساله
    print("You have not performed any recorded activity.");
  } else {
    //  طباعة النتائج النهائية طباعه التمارين التي مارسها المستخدم
    practicedTypes.forEach((type) => print("- $type"));
  }

  //  التحقق من "Running" اذا كان قد سجلها المستخدم
  if (practicedTypes.contains("Running") || practicedTypes.contains("running")) {
    print("\nSearch result: Congratulations! You've successfully recorded your Running session!");
    list.whereType<RunningActivity>().first.sendReminder("Running");
  } else {
    print("\nSearch result: You did not practice running.");
  }
}

void manageDailySteps(Map<String, int> stepsMap) {
  print("--- Executing Daily Log Operations ---");

// تحديث تاريخ واحد
  stepsMap["2023-10-01"] = 12000;
  print("Steps for 2023-10-01 updated.");

// حذف يوم واحد
  stepsMap.remove("2023-10-03");
  print("Log for 2023-10-03 deleted.");
  print("\n--- Final Step Log ---");
// طباعه جميع الايام مع البيانات
  stepsMap.forEach((date, steps) {
    print("Date: $date Steps: $steps");
  });

// SportsCalculator حساب مجموع الخطوات الكلي من خلال استدعاء الداله من كلاس
  int totalSteps = SportsCalculator.calculateTotalSteps(stepsMap.values);
  print("\n");
  print("Total Step Count: $totalSteps steps");
}

// وظيفه هذه الداله اضافه نشيط جديد
void addWorkout(String type, int duration, double extraParam) {
  //التحقق من المده هل هي موجبه
  if (duration <= 0) {
    throw InvalidWorkoutDataException('Duration must be positive', 'duration');
  }
  // انشاء كائن من نوع نشاط
  Activity newActivity;

  // تحديد الكلاس المستخدم من خلال نوع النشاط
  if (type == "Running") {
    newActivity = RunningActivity(duration, extraParam);
  } else if (type == "Swimming") {
    newActivity = SwimmingActivity(duration, extraParam.toInt());
  } else {
    newActivity = Activity(type, duration, 0); // النشاط الاب
  }
  // اضافه نشاط لقائمه الانشطه
  list.add(newActivity);
  print("\n--- Workout Logged Successfully ---");
  print("Activity: ${newActivity.type} ($duration mins)");
  // طباعه الخطه الخاص بالنشاط
  print("Warmup: ${newActivity.plan.warmup}"); // طباعة الإحماء
  print("Cooldown: ${newActivity.plan.cooldown}"); // طباعة التبريد
  print("\n");
}

//  دالة الوسيط مهمتها تسجيل الخطا
void processWorkoutData(String type, int duration, double extraParam) {
  try {
    addWorkout(type, duration, extraParam);
  } catch (e) {
    print("Log: Error detected in $type, rethrowing...");
    // قذف الخطا لداله main
    rethrow;
  }
}

// دالة تشغيل المحاكاة للعمليات غير المتزامنة والمتعددة (Asynchrony & Concurrency)
Future<void> _runSimulations() async {
  print("\n--- 🏁 Starting Full Day Simulation (Part 5) ---");

  //  تشغيل جلب الطقس في الخلفية (Future)
  FitnessService.fetchWeatherData().then((result) {
    print("Weather update received: $result");
  });

  //  البدء بتحديثات الخطوات (Stream) - محاكاة الحركة خلال اليوم
  print("Step Counter Started. Goal: 50 steps for today...");

  await for (int steps in FitnessService.simulateStepCounter()) {
    print(">> Steps Walked: $steps");

    // الشرط المطلوب: عند الوصول لـ 50 خطوة (محاكاة لـ 5000)
    //print(practicedTypes);
    if (steps == 50) {
      if (practicedTypes.contains("Running") || practicedTypes.contains("running")) {
        list
            .whereType<RunningActivity>()
            .first
            .notifyGoalReached(steps);
      }
      // الآن فقط نحسب السعرات الإجمالية باستخدام Future (كما طلب المشروع)
      print("Calculating calories burned for this goal...");
      double total = await FitnessService.calculateTotalCalories(list);
      print("Total Calories burned: $total");
    }
  }

  // الانتقال للمعالجة المتوازية (Isolate) لحساب الإحصائيات الأسبوعية
  print("\nMoving to Background Processing (Weekly Stats)...");
  ReceivePort receivePort = ReceivePort();
  await Isolate.spawn(FitnessService.calculateWeeklyStats, receivePort.sendPort);

  var messages = StreamIterator(receivePort);
  if (await messages.moveNext()) {
    SendPort sendToIsolate = messages.current;

    // إرسال البيانات للـ Isolate
    sendToIsolate.send({
      'calories': list.map((e) => e.caloriesBurned).toList(),
      'steps': dailySteps.values.toList() // تأكد أن dailySteps معرفة في الـ Main
    });

    if (await messages.moveNext()) {
      var finalStats = messages.current;
      print("✅ Final Weekly Summary from Isolate: $finalStats");
    }
  }
  receivePort.close();
}