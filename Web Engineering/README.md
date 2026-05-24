
# 🎯 Smart Home Services Booking Platform (Mike2)

## 📖 Project Brief & Overview
This project is a comprehensive web-based platform designed to streamline **Home Services Bookings** (such as carpentry, plumbing, electrical work, and cleaning). It effectively bridges the gap between customers looking for reliable service providers and professionals seeking to manage their schedules, showcase services, and scale their client base through an intuitive, automated booking workflow.

---

## 🏗️ Architectural Design & Tech Stack

The application strictly adheres to a multi-tiered architecture, enforcing **SOLID** design principles and **Clean Code** conventions:
* **Core Architectural Pattern:** MVC (Model-View-Controller)
* **Backend Framework:** ASP.NET Core MVC
* **Data Access Layer (DAL):** Entity Framework Core (ORM)
* **Database Management System:** SQL Server
* **Identity & Security:** ASP.NET Core Identity (Authentication & Role-Based Authorization)
* **Frontend UI:** Bootstrap 5 + Razor Views

---

## 🗂️ Project Directory Structure

```text
📁 mike2/                 # Main Solution Folder
├── 📁 Controllers/       # MVC Controllers handling business logic (Admin, Bookings, Services)
├── 📁 Models/            # Domain Models & Data Entities (ApplicationUser, Booking, Service)
├── 📁 Views/             # Razor Views for UI Layouts (Customer, Provider, and Admin Portals)
├── 📁 Data/              # Data Layer holding ApplicationDbContext and SeedData scripts
├── 📁 Areas/             # Managed ASP.NET Core Identity scaffolding and account configurations
├── Program.cs            # Application entry point, service registrations, and DI container setup
└── appsettings.json      # Global configuration settings and Database Connection Strings

```

---

## 👥 System Actors & Role Capabilities

1. **Customer:** Can browse available home services filtered by category, price, and location; review provider profiles along with historic ratings; book real-time available time slots; and post verified star ratings and text reviews upon service completion.
2. **Service Provider:** Manages their professional profile (experience, base rates, covered regions); configures operational availability calendars; and receives immediate booking requests with full autonomy to accept or reject them (with an optional reason).
3. **Administrator (Admin):** Exercises global platform governance including user account management (activating/suspending accounts), managing core system service catalogs, monitoring and moderating user feedback to purge explicit behavior, and extracting system performance reports.

---

## 💾 Database Schema & Structural Relationships

The application maps out a robust relational database schema carefully designed to prevent double-booking conflicts and maintain data integrity:

* **Users:** Handles core identity profiles, access credentials, structural system roles (`Role`), and active flags (`IsActive`).
* **AppServiceProviders:** Holds professional provider credentials linked to the main Users table via a ($1:1$) relationship.
* **Services:** Catalog of services offered by each individual provider under a ($1:N$) structural hierarchy.
* **Availabilities:** Tracking calendars dedicated to provider operational hours, preventing overlapping bookings.
* **Bookings:** The centralized intersection table connecting Customer, Provider, Service, and specific Availability slots, dynamically updating request states (`Pending`, `Accepted`, `Completed`, `Rejected`).
* **Reviews & Notifications:** Secondary tables providing validated feedback loops ($1:1$ mapping to completed bookings) and instantaneous user-alert updates triggered by transactional status changes.

---

## 🚀 Installation & Setup Guide

### Prerequisites

* .NET SDK (matching the targeted project release versions)
* SQL Server Express or LocalDB instance

### Quick Start Execution

```bash
# 1. Clone the repository
# Clone the entire repository
git clone https://github.com/OmarHKhalil/University-Projects.git

# Navigate into the venezia-gym-flutter directory
cd University-Projects/Web Engineering/mike2

# 2. Apply Entity Framework Migrations to build the local database schema
dotnet ef database update

# 3. Compile and launch the application locally
dotnet run

```

### 🔑 Seed Account Credentials (For Testing & Evaluation)

The database automatically seeds mock accounts to facilitate smooth scenario walk-throughs and project evaluations:

* **Administrator Account:** `admin@demo.com` | Password: `Admin123!`
* **Test Customer Account:** `customer1@demo.com` | Password: `Customer123!`
* **Test Provider Account:** `cleaner1@demo.com` | Password: `Provider123!`

