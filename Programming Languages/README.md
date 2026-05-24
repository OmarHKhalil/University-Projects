
# 🏥 Hospital Management System

An integrated, interactive Python console application designed to manage doctor and patient records efficiently, using a local **SQLite** database for secure data persistence. It also includes graphical login features and smart reporting capabilities.

---

## ✨ Key Features

### 👨‍⚕️ Doctor Management
* **Registration & Validation:** Add new doctors with strict real-time validation for name formats, emails, and 10-digit phone numbers.
* **Safe Deletion:** A built-in integrity check prevents deleting any doctor who still has active patients assigned, ensuring data safety.
* **Specialty Search:** Easily filter and view available doctors based on their medical specializations.

### 📑 Patient Management
* **Admissions & Linking:** Register patients, validate their basic contact details, and link them directly to a primary physician via Doctor ID.
* **Disease Tracking:** Look up patient medical histories and records using dynamic disease keywords.

### 📊 Reports & Interfaces
* **Data Export (PDF & Excel):** Generate clean, professional tabular reports for doctors and patients in PDF (via ReportLab) or Excel format (via Pandas) instantly.
* **Doctor GUI Login:** Features an embedded graphical user interface built with **Tkinter** for secure doctor authentication.

---

## 🛠️ Tech Stack

* **Core Language:** Python 3
* **Database Engine:** SQLite3
* **GUI Framework:** Tkinter
* **External Dependencies:** Pandas, ReportLab, OpenPyXL (for Excel output handling).

---

## 🚀 Setup & Execution

### 1. Install Dependencies
Before running the system, install the required third-party libraries using your terminal:
```bash
pip install reportlab pandas openpyxl

```

### 2. Launch the Application

Since the project is built inside a Jupyter Notebook, you can launch it using either of the following methods:

**Method 1: Via Jupyter Interface (Recommended)**

1. Open your terminal in the project directory and run:
```bash
jupyter notebook

```


2. Click on `hospital_system.ipynb` from the browser dashboard.
3. Run all cells to start the application interface directly inside the notebook.

**Method 2: Via Terminal (Using Nbconvert)**
If you want to execute the notebook directly from the command line without opening the browser interface, run:

```bash
jupyter nbconvert --to script hospital_system.ipynb && python hospital_system.py

```

---

## 📁 Database Schema

* **Doctors Table:** Fields include (`id`, `name`, `email`, `age`, `phone`, `specialty`, `password`).
* **Patients Table:** Fields include (`id`, `name`, `email`, `age`, `phone`, `disease`, `doctor_id`), where `doctor_id` serves as a Foreign Key.

---
