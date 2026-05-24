
# 🛡️ OWASP Juice Shop Vulnerabilities & Attack Report

This repository contains a detailed cybersecurity research and penetration testing report conducted on the **OWASP Juice Shop** web application. The project demonstrates core web vulnerabilities, exploitation methodologies using **Burp Suite**, and provides defensive remediation strategies.

---

## 👥 Project Details
* **University:** Arab International University (AIU)
* **Faculty:** Information & Communication Engineering
* **Course:** Information Systems Security (ISS)
* **Supervised by:** Eng. Tamer Tamer
* **Developed by:** * Mohamed Manar Hussin (202110037)
  * Omar Hafez Khalil (202110479)

---

## 🎯 Vulnerabilities Exploited

### 1. Brute Force Attack
* **Description:** Guessing user credentials by trying multiple password combinations due to weak password policies and the absence of rate-limiting.
* **Exploitation Steps:**
  1. Intercepted the login request using **FoxyProxy** and **Burp Suite**.
  2. Sent the captured request to **Burp Intruder** using the `Sniper` attack type.
  3. Set payloads to point at the password parameter and loaded a wordlist.
  4. Successfully identified the correct password via the `200 OK` status code response.
* **Remediation:** * Implement account lockout policies after consecutive failed attempts (Rate Limiting).
  * Enforce Strong Password Policies and Multi-Factor Authentication (MFA).

---

### 2. SQL Injection (SQLi)
* **Attack 1: Authentication Bypass**
  * **Payload used:** `' OR '1'='1;--`
  * **Mechanism:** Bypasses the login interface by forcing the SQL query condition to evaluate to `TRUE`, discarding the password check using the `--` comment.
* **Attack 2: Data Extraction via UNION SELECT**
  * **Payload used:** `UNION SELECT sql,'1','1','1','2','3','7','8','9' FROM sqlite_master--`
  * **Mechanism:** Injected into the search query (`q`) to dump the database schema and retrieve unauthorized structural details of the system.
* **Remediation:**
  * Use **Prepared Statements (Parameterized Queries)**.
  * Validate and sanitize all user inputs before executing SQL commands.

---

### 3. Broken Access Control (IDOR) & Parameter Tampering
* **Attack 1: Viewing Other Users' Baskets**
  * **Mechanism:** Modifying the `basket` parameter ID inside Burp Suite Repeater to access confidential data belonging to other shoppers.
* **Attack 2: Negative Quantity Exploitation (Money Hack)**
  * **Mechanism:** Intercepting the add-to-basket request and changing the item quantity to a negative value. This manipulates the final checkout sum, reducing the total costs or creating a negative balance trick.
* **Remediation:**
  * Implement robust **Role-Based Access Control (RBAC)**.
  * Use indirect or randomized tokens (UUIDs) instead of sequential integers for resource IDs.

---

## 📁 Repository Content
* `README.md` - The complete architectural breakdown of the attacks.
* `iss final project manar &omar.docx` - The official and comprehensive project report document.

---
*Disclaimer: This report is purely for educational and ethical hacking purposes under academic supervision.*
