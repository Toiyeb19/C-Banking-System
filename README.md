### Bank System README 

# Secure Banking Management System

A robust, cross-platform CLI banking application written in C. Unlike standard student projects, this system features full data persistence using file handling, ensuring user data and transaction history are saved permanently.

## Features

* **Data Persistence:** Uses custom File I/O to store account details, passwords, and transaction logs. Data remains available even after the program closes.
* **Secure Authentication:** Implements a password-protected login system to ensure user privacy.
* **Cross-Platform Compatibility:** Optimized to run smoothly on both macOS (using `clear`) and Windows (using `cls`).
* **Financial Operations:** Handles deposits, withdrawals with balance validation, and account metadata updates.

## Technical Highlights
* **Safe Input Handling:** Utilizes `fgets` and buffer clearing to prevent buffer overflow vulnerabilities.
* **Modular Architecture:** Code is structured into distinct modules (`create`, `view`, `transaction`) for maintainability.

## How to Run

1. Compile the code using GCC:
   '''bash
   gcc main.c -o bank_app
