#include "study_timer.h"
#include "task_manager.h"
#include <iostream>
#include <limits>
#include <string>

// Function prototypes
void display_menu();
void process_choice(int choice, TaskManager &task_manager, StudyTimer &timer);

// Functions for handling task creation
void add_assignment(TaskManager &task_manager);
void add_study_session(TaskManager &task_manager);

// Functions for timer operations
void start_timer(StudyTimer &timer);
void stop_timer(StudyTimer &timer);

int main() {
  std::cout << "====================================" << std::endl;
  std::cout << "   WELCOME TO STUDY BUDDY v1.0     " << std::endl;
  std::cout << "====================================" << std::endl;

  TaskManager task_manager;
  StudyTimer timer;

  bool exit_program = false;
  int choice = 0;

  // Try to load saved tasks
  task_manager.load_from_file("tasks.txt");

  while (!exit_program) {
    display_menu();

    std::cout << "Enter your choice: ";
    if (!(std::cin >> choice)) {
      std::cout << "Invalid input. Please enter a number." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    if (choice == 0) {
      exit_program = true;
      task_manager.save_to_file("tasks.txt");
      std::cout << "Thank you for using Study Buddy!" << std::endl;
    } else {
      process_choice(choice, task_manager, timer);
    }
  }

  return 0;
}

void display_menu() {
  std::cout << "\n===== MAIN MENU =====" << std::endl;
  std::cout << "1. Add Assignment" << std::endl;
  std::cout << "2. Add Study Session" << std::endl;
  std::cout << "3. View All Tasks" << std::endl;
  std::cout << "4. View Assignments" << std::endl;
  std::cout << "5. View Study Sessions" << std::endl;
  std::cout << "6. Search Tasks" << std::endl;
  std::cout << "7. Sort Tasks by Priority" << std::endl;
  std::cout << "8. Start Study Timer" << std::endl;
  std::cout << "9. Stop Study Timer" << std::endl;
  std::cout << "10. View Study Time Summary" << std::endl;
  std::cout << "11. Remove a Task" << std::endl;
  std::cout << "0. Exit" << std::endl;
  std::cout << "====================" << std::endl;
}

void process_choice(int choice, TaskManager &task_manager, StudyTimer &timer) {
  switch (choice) {
    case 1:
      add_assignment(task_manager);
      break;
    case 2:
      add_study_session(task_manager);
      break;
    case 3:
      task_manager.display_all_tasks();
      break;
    case 4:
      task_manager.display_assignments();
      break;
    case 5:
      task_manager.display_study_sessions();
      break;
    case 6: {
      std::string keyword;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline before getline
      std::cout << "Enter search keyword: ";
      std::getline(std::cin, keyword);
      task_manager.search_tasks(keyword);
      break;
    }
    case 7:
      task_manager.sort_by_priority();
      break;
    case 8:
      start_timer(timer);
      break;
    case 9:
      stop_timer(timer);
      break;
    case 10:
      timer.display_summary();
      break;
    case 11: {
      int index;
      std::cout << "Enter task number to remove: ";
      if (!(std::cin >> index)) {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      task_manager.remove_task(index - 1); // Convert to 0-based index
      break;
    }
    default:
      std::cout << "Invalid choice. Please try again." << std::endl;
      break;
  }
}

void add_assignment(TaskManager &task_manager) {
  std::string title, description, course, due_date;
  int priority;

  std::cout << "\n=== Add New Assignment ===" << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Title: ";
  std::getline(std::cin, title);

  std::cout << "Description: ";
  std::getline(std::cin, description);

  std::cout << "Course: ";
  std::getline(std::cin, course);

  std::cout << "Due Date: ";
  std::getline(std::cin, due_date);

  std::cout << "Priority (1-5, 5 is highest): ";
  std::cin >> priority;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (priority < 1) priority = 1;
  if (priority > 5) priority = 5;

  task_manager.add_assignment(title, description, priority, course, due_date);
  std::cout << "Assignment added successfully!" << std::endl;
}

void add_study_session(TaskManager &task_manager) {
  std::string title, description, subject;
  int priority, duration;

  std::cout << "\n=== Add New Study Session ===" << std::endl;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Title: ";
  std::getline(std::cin, title);

  std::cout << "Description: ";
  std::getline(std::cin, description);

  std::cout << "Subject: ";
  std::getline(std::cin, subject);

  std::cout << "Duration (minutes): ";
  std::cin >> duration;

  std::cout << "Priority (1-5, 5 is highest): ";
  std::cin >> priority;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  if (priority < 1) priority = 1;
  if (priority > 5) priority = 5;
  if (duration < 0) duration = 0;

  task_manager.add_study_session(title, description, priority, subject, duration);
  std::cout << "Study session added successfully!" << std::endl;
}

void start_timer(StudyTimer &timer) {
  if (timer.is_running()) {
    std::cout << "Timer is already running for " << timer.get_current_subject() << std::endl;
    return;
  }

  std::string subject;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cout << "Enter subject to study: ";
  std::getline(std::cin, subject);

  timer.start(subject);
}

void stop_timer(StudyTimer &timer) {
  if (!timer.is_running()) {
    std::cout << "No timer is currently running." << std::endl;
    return;
  }

  timer.stop();
}
