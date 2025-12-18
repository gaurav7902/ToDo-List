# To-Do List Management System (C++)

A console-based **To-Do List Management System** developed in **C++** using **Object-Oriented Programming** and **file handling**.  
The application allows users to manage tasks efficiently with persistent storage.

---

## 🚀 Features

- Add new tasks
- View all tasks with completion status
- Mark tasks as completed
- Delete existing tasks
- Persistent storage using text file handling
- Menu-driven user interface

---

## 🛠️ Tech Stack

- **Language:** C++
- **Core Concepts:**
  - Object-Oriented Programming (Classes, Encapsulation)
  - STL (`vector`, `string`)
  - File Handling (`ifstream`, `ofstream`)
  - Modular and clean code design

---

## 📁 Project Structure

```
├── todo.cpp
├── tasks.txt (auto-generated on first run)
```

---

## ▶️ How to Compile and Run

### Compile

```bash
g++ todo.cpp -o todo
./todo
```

---

## 💾 Data Storage

Tasks are stored persistently in a text file (`tasks.txt`) using a delimiter-based format:

```
task_id | task_description | completion_status
```

This approach avoids unsafe binary serialization and ensures portability.

---

## 🧠 Design Overview

### Task Class

- Stores task ID, description, and completion status
- Handles serialization and deserialization

### TodoList Class

- Manages all task operations
- Handles file I/O and data persistence

---

## 🔍 Sample Menu

1. Add Task
2. View Tasks
3. Mark Task as Completed
4. Delete Task
5. Exit

---

## 📈 Possible Enhancements

- Task priorities and due dates
- Search and filter tasks
- Sorting by completion or priority
- GUI using Qt
- Database or cloud storage integration

---

## 👨‍💻 Author

**Gaurav Patidar**  
B.Tech – Computer Science and Engineering