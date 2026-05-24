
# Venezia Gym Management Ecosystem (Flutter Application)

A modern, highly responsive, and visually striking cross-platform mobile application interface for a fitness ecosystem named **VENEZIA GYM**, built using **Flutter** and **Material 3**.

This repository showcases production-grade clean UI/UX architecture tailored for fitness services, utilizing a bold, high-contrast color palette (deep charcoal and luxurious gold/amber) along with modular code separation to ensure optimal performance, screen adaptability, and developer maintainability.

---

## 🎨 UI/UX Layout & Architectural Breakdown

### 1. Application Entry Point (`main.dart`)
* **Material 3 Integration:** Initializes the core rendering engine leveraging the modern `Material 3` design standard.
* **Streamlined Routing:** Sets up the application pipeline and designates the `LoginScreen` as the default home gateway, while disabling the default debug corner banner (`debugShowCheckedModeBanner: false`) for a clean, production-ready aesthetic.

### 2. The Authentication Gateway (`login.dart`)
* **Layering & Depth:** Employs a `Stack` layout combined with `Clip.none` to allow a custom circular dumbbell widget to float smoothly over the card container boundaries, creating an eye-catching 3D depth effect.
* **Viewport Safety:** Wraps input structures inside a `SingleChildScrollView` paired with `resizeToAvoidBottomInset: true` to prevent any runtime view constraint or keyboard `Overflow` errors when entering user details.
* **Adaptive Constraints:** Wraps the primary interaction card in a `ConstrainedBox` with a `maxWidth: 420` specification, preventing abnormal horizontal stretching when executed on wide screens or tablets.

### 3. The Member Dashboard (`welcome.dart`)
* **Custom Styling:** Designed with flat elevations (`elevation: 0`) and bottom-curved corner shapes (`RoundedRectangleBorder`) to achieve a seamless visual hierarchy and automatically suppress default back-navigation triggers.
* **Component Reusability:** Features a modular footer navigation segment constructed using a custom functional builder method (`_buildFooterItem`). This manages components dynamically, switching active item highlighting, color opacities, and font weights based on the current selection state (`isActive`).

---

## 📂 Project Architecture

The application layout isolates structural logic from rendering views to enforce clean code segregation and predictable routing pathways:

```text
lib/
├── main.dart           # App bootstrapper, global theme manager, and root routing configuration
├── login.dart          # Secure credential layout, gold-accented input styling, and stateful tracking
└── welcome.dart        # Member landing control board & modular navigation footer bars

```

---

## 🔄 Dynamic Navigation Flow

The platform handles application routing explicitly. When a member successfully populates their credentials (Member ID and Password) and triggers the gold-accented **START WORKOUT** interaction button, the system executes the local callback routine `_loginPressed` to transition the view stack to the member dashboard seamlessly:

```dart
void _loginPressed() {
  Navigator.of(context).push(
    MaterialPageRoute(builder: (context) => const WelcomeScreen()),
  );
}

```

---

## 💻 Setup & Execution Environment

### Prerequisites

* Ensure you have the [Flutter SDK](https://docs.flutter.dev/get-started/install) installed (Compatible with Dart 3.x or higher).
* An Android/iOS Emulator or a physical testing device configured for local execution.

### Quick Start

1. Clone this repository onto your workstation:

```bash
# Clone the entire repository
git clone https://github.com/OmarHKhalil/University-Projects.git

# Navigate into the venezia-gym-flutter directory
cd Mobile Application Projects/venezia-gym-flutter
```

2. Pull the dependencies declared inside your `pubspec.yaml` manifest:

```bash
   flutter pub get

```

3. Boot up your target terminal or emulator instance and build the target framework:

```bash
   flutter run

```

```
