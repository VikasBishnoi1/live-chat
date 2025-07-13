# Live Chat Queue Balancer using Circular Queue

### 👨‍💻 Internship Project by Vikas Bishnoi  
**Project Title**: Mastering Live Chat Queue Balancer using Circular Queue  
**Language**: C++  
**Date**: July 2025

---

## 📌 Objective

This project simulates a **Live Chat Support Queue System**, where users are added to a waiting queue and assigned to available agents in a **First-Come-First-Served** manner. It uses a **Circular Queue** for efficient memory management and logs all activity with timestamps.

---

## 🛠️ Features

- ➕ Add users to the chat queue  
- 🧑‍💻 Assign users to support agents  
- 📋 Display current queue with join time  
- 🕒 Timestamp for all actions  
- 📝 Logging to `chat_log.txt`  
- 🔄 Efficient Circular Queue implementation  
- ❌ Handles queue full/empty gracefully  
- 🧩 Modular C++ design (using classes and headers)

---

## 📂 File Structure

```text
📦 LiveChatQueueProject/
├── main.cpp                 # Main menu-driven program
├── ChatQueueBalancer.h      # Header file with class definition
├── ChatQueueBalancer.cpp    # Circular queue logic and logging
├── chat_log.txt             # Auto-generated log file
├── README.md                # This documentation file
