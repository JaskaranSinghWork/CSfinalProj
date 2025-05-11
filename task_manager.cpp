#include "task_manager.h"
#include <algorithm>
#include <iostream>

TaskManager::TaskManager() {}

TaskManager::~TaskManager() {
  // Clean up allocated memory
  for (Task *task : tasks) {
    delete task;
  }
  tasks.clear();
}

void TaskManager::add_assignment(const std::string &title,
                                 const std::string &description, int priority,
                                 const std::string &course,
                                 const std::string &due_date) {
  tasks.push_back(
      new Assignment(title, description, priority, course, due_date));
}

void TaskManager::add_study_session(const std::string &title,
                                    const std::string &description,
                                    int priority, const std::string &subject,
                                    int duration_minutes) {
  tasks.push_back(new StudySession(title, description, priority, subject,
                                   duration_minutes));
}

void TaskManager::display_all_tasks() const {
  if (tasks.empty()) {
    std::cout << "No tasks to display." << std::endl;
    return;
  }

  std::cout << "\n===== ALL TASKS ===== [" << tasks.size() << " tasks]\n"
            << std::endl;
  for (size_t i = 0; i < tasks.size(); i++) {
    std::cout << "Task #" << (i + 1) << std::endl;
    tasks[i]->display();
    std::cout << std::endl;
  }
}

void TaskManager::display_assignments() const {
  std::cout << "\n===== ASSIGNMENTS =====\n" << std::endl;
  bool found = false;

  for (size_t i = 0; i < tasks.size(); i++) {
    if (tasks[i]->get_type() == "Assignment") {
      std::cout << "Assignment #" << (i + 1) << std::endl;
      tasks[i]->display();
      std::cout << std::endl;
      found = true;
    }
  }

  if (!found) {
    std::cout << "No assignments to display." << std::endl;
  }
}

void TaskManager::display_study_sessions() const {
  std::cout << "\n===== STUDY SESSIONS =====\n" << std::endl;
  bool found = false;

  for (size_t i = 0; i < tasks.size(); i++) {
    if (tasks[i]->get_type() == "StudySession") {
      std::cout << "Study Session #" << (i + 1) << std::endl;
      tasks[i]->display();
      std::cout << std::endl;
      found = true;
    }
  }

  if (!found) {
    std::cout << "No study sessions to display." << std::endl;
  }
}

void TaskManager::sort_by_priority() {
  //Simple bubble sort for practice (not efficient for large lists)
  for (size_t i = 0; i < tasks.size(); i++) {
    for (size_t j = 0; j < tasks.size() - 1 - i; j++) {
      if (tasks[j]->get_priority() < tasks[j + 1]->get_priority()) {
        Task *temp = tasks[j];
        tasks[j] = tasks[j + 1];
        tasks[j + 1] = temp;
      }
    }
  }

  std::cout << "Tasks sorted by priority (highest to lowest)." << std::endl;
}

bool TaskManager::save_to_file(const std::string &filename) {
  std::ofstream file(filename);

  if (!file.is_open()) {
    std::cout << "Error: Could not open file for writing." << std::endl;
    return false;
  }
  for (Task *task : tasks) {
    if (task->get_type() == "Assignment") {
      Assignment *assignment = static_cast<Assignment *>(task);
      file << "Assignment|" << assignment->get_title() << "|"
          
           << assignment->get_description() << "|" << assignment->get_priority()
           << "|" << assignment->get_course() << "|"
           << assignment->get_due_date() << std::endl;
        
    } else if (task->get_type() == "StudySession") {
      StudySession *study = static_cast<StudySession *>(task);
        
      file << "StudySession|" << study->get_title() << "|"
           << study->get_description() << "|" << study->get_priority() << "|"
           << study->get_subject() << "|" << study->get_duration() << std::endl;
    }
  }

  file.close();
  std::cout << "Tasks saved to file: " << filename << std::endl;
  return true;
}

Task *TaskManager::parse_task_from_line(const std::string &line) {
  std::string type, title, description, extra1, extra2;
  int priority, duration;

  std::istringstream strm(line);

  // Parse first part to determine type
  std::getline(strm, type, '|');
  std::getline(strm, title, '|');
  std::getline(strm, description, '|');
  std::string priority_str;
  std::getline(strm, priority_str, '|');
  priority = std::stoi(priority_str);

  if (type == "Assignment") {
    std::getline(strm, extra1, '|'); // course
    std::getline(strm, extra2);      // due_date
    return new Assignment(title, description, priority, extra1, extra2);
      
  } else if (type == "StudySession") {
    std::getline(strm, extra1, '|'); // subject

    std::string duration_str;
    std::getline(strm, duration_str);
    duration = std::stoi(duration_str);

    return new StudySession(title, description, priority, extra1, duration);
  }

  return nullptr;
}

bool TaskManager::load_from_file(const std::string &filename) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cout << "Error: Could not open file for reading." << std::endl;
    return false;
  }

  // Clear existing tasks
  for (Task *task : tasks) {
    delete task;
  }
  tasks.clear();

  std::string line;
  while (std::getline(file, line)) {
    Task *task = parse_task_from_line(line);
    if (task != nullptr) {
      tasks.push_back(task);
    }
  }

  file.close();
  std::cout << "Tasks loaded from file: " << filename << std::endl;
  return true;
}

void TaskManager::search_tasks(const std::string &keyword) const {
  std::cout << "\n===== SEARCH RESULTS FOR '" << keyword << "' =====\n"
            << std::endl;
  bool found = false;

  for (size_t i = 0; i < tasks.size(); i++) {
    // Search in title and description
    if (tasks[i]->get_title().find(keyword) != std::string::npos ||
        tasks[i]->get_description().find(keyword) != std::string::npos) {

      std::cout << "Task #" << (i + 1) << std::endl;
      tasks[i]->display();
      std::cout << std::endl;
      found = true;
    }
  }

  if (!found) {
    std::cout << "No tasks found matching '" << keyword << "'." << std::endl;
  }
}

int TaskManager::get_task_count() const { return tasks.size(); }

bool TaskManager::remove_task(int index) {
  if (index < 0 || index >= static_cast<int>(tasks.size())) {
    std::cout << "Error: Invalid task index." << std::endl;
    return false;
  }

  delete tasks[index];
  tasks.erase(tasks.begin() + index);
  std::cout << "Task #" << (index + 1) << " removed." << std::endl;
  return true;
}