Study Buddy - Task Management System

Project Overview
Study Buddy is a console-based task management application designed to help students organize their academic workload. The system allows users to track assignments, plan study sessions, and monitor study time.

Features
- Create and manage assignments with details like title, description, course, and due date
- Plan study sessions with subject and duration information
- Set priority levels (1-5) for tasks
- Record and track study time for different subjects
- Search for tasks using keywords
- Sort tasks by priority
- Save data between sessions
- Simple console user interface

C++ Concepts Used
Classes and Inheritance
- Base `Task` class with derived `Assignment` and `StudySession` classes
   - Virtual methods for polymorphism
   - Abstract base class with pure virtual functions

Pointers and Memory Management**
- Dynamic allocation of task objects
- Pointers to handle polymorphic objects
- Manual memory management (allocation/deallocation)

File Streams
- Reading and writing data to files
- Using string streams for string parsing

Data Structures
- Vectors for storing collections of tasks and time records
- Custom structures for time tracking

Files in the Project
task.h: Defines the Task hierarchy (base Task class and derived classes)
task_manager.h: Manages a collection of tasks (add, remove, search, sort)
study_timer.h: Tracks study time for different subjects
main.cpp: Contains the user interface and main program loop
test.cpp: Contains unit tests for the classes

How to Compiler and Run
1. Run "make" to build the application
2. Run ./study_buddy to start the application 
Example Usage
===================================
   WELCOME TO STUDY BUDDY v1.0
===================================

===== MAIN MENU =====
1. Add Assignment
2. Add Study Session
3. View All Tasks
4. View Assignments
5. View Study Sessions
6. Search Tasks
7. Sort Tasks by Priority
8. Start Study Timer
9. Stop Study Timer
10. View Study Time Summary
11. Remove a Task
0. Exit
====================
Enter your choice: 1

=== Add New Assignment ===
Title: Math Homework
Description: Complete exercises 1-10
Course: MATH101
Due Date: 2025-05-15
Priority (1-5, 5 is highest): 4
Assignment added successfully!
```

Future Improvements
- Add graphical user interface
- Implement due date notifications
- Integrate with calendar applications
- Implement a Pomodoro timer feature
- Add statistics and reports for study habits

This project was made for COMPSCI II FINAL.