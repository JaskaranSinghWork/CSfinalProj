#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include <fstream>
#include <sstream>
#include <vector>

class TaskManager {
public:
  // Constructor
  TaskManager();

  // Destructor to clean up memory
  ~TaskManager();

  // Add tasks
  void add_assignment(const std::string &title, const std::string &description,
                      int priority, const std::string &course,
                      const std::string &due_date);
  void add_study_session(const std::string &title,
                         const std::string &description, int priority,
                         const std::string &subject, int duration_minutes);

  // Display all tasks
  void display_all_tasks() const;

  // Display tasks of a specific type
  void display_assignments() const;
  void display_study_sessions() const;

  // Sort tasks by priority (high to low)
  void sort_by_priority();

  // Save tasks to file
  bool save_to_file(const std::string &filename);

  // Load tasks from file
  bool load_from_file(const std::string &filename);

  // Search for tasks containing a keyword
  void search_tasks(const std::string &keyword) const;

  // Get task count
  int get_task_count() const;

  // Remove a task by index
  bool remove_task(int index);

private:
  std::vector<Task *> tasks;
  // Helper function to parse a line from file
  Task *parse_task_from_line(const std::string &line);
};

#endif // TASK_MANAGER_H