

```markdown
# Fitness Tracker System (Dart CLI Application)

An advanced Dart Console Application developed as a comprehensive assignment for the **Mobile Programming** course at the **Arab International University (AIU)** - Faculty of Informatics Engineering.

This project showcases a complete implementation of core and advanced Dart programming concepts, ranging from basic data structures to multi-threaded asynchronous processing.

---

## 🚀 Key Features & Architectural Coverage

The application is structured to demonstrate proficiency across 5 key areas of the Dart language:

### 1. Core Basics & Health Metrics
* **Dynamic Assessments:** Calculates Body Mass Index (BMI) using user metrics and classifies weight status (Underweight, Normal, Overweight, Obese).
* **Categorization:** Classifies age brackets using control flow statements (`switch-case`).
* **Goal Setting:** Forecasts steps goals leveraging loop iterations.

### 2. Advanced Collections & Data Manipulation
* **Data Management:** Utilizes structured `List`, `Set`, and `Map` definitions to store, update, filter, and track exercise sessions.
* **Modern Dart Operators:** Implements the `Spread operator (...)` and `Null-aware spread operator (...?)` for safe collections merging.

### 3. Object-Oriented Programming (OOP)
* **Encapsulation:** Uses private fields with standard getters and setters.
* **Polymorphism & Inheritance:** Features an abstract base `CalorieCalculator` and concrete sub-classes (`RunningActivity` and `SwimmingActivity`).
* **Mixins & Consts:** Includes a `Reminder` mixin for behavioral updates and optimized `const Constructors` for static workout blueprints.

### 4. Robust Error Handling
* **Custom Exceptions:** Implements `InvalidWorkoutDataException` to target invalid runtime fields (e.g., negative calories or zero duration).
* **Control Flow:** Utilizes `try-catch-on-finally` structures accompanied by `rethrow` mechanisms for localized logging and global error management.

### 5. Asynchronous & Concurrent Programming
* **Futures & Async/Await:** Simulates network API fetching (e.g., weather updates) and handles time-delayed aggregate calculations.
* **Streams:** Provides real-time step counter tracking utilizing asynchronous generators (`async*` and `yield`).
* **Isolates (Multi-threading):** Offloads heavy mathematical metrics (weekly statistics compilation) to a background thread to prevent main execution thread blocking.

---

## 📂 Project Directory Structure

Following professional Dart conventions, the code is modularized as follows:

```text
lib/
├── models/
│   ├── activity.dart
│   ├── running_activity.dart
│   ├── swimming_activity.dart
│   └── workout_plan.dart
├── mixins/
│   └── reminder.dart
├── exceptions/
│   └── invalid_workout_exception.dart
├── utils/
│   ├── fitness_service.dart
│   └── constants.dart
│   └── SportsCalculator.dart
└── main.dart

```

---

## 💻 How to Run the Project

### Prerequisites

Make sure you have the [Dart SDK](https://dart.dev/get-dart) installed on your machine.

### Execution

1. Clone this repository:

```bash
   git clone [https://github.com/YOUR_USERNAME/fitness-tracker-dart.git](https://github.com/YOUR_USERNAME/fitness-tracker-dart.git)

```

2. Navigate into the project folder:

```bash
   cd fitness-tracker-dart

```

3. Run the application:

```bash
   dart lib/main.dart

```



```