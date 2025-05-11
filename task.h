#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

// Base Task class - represents a generic task
class Task {
public:
  // Constructors
  Task();
  Task(const std::string &title, const std::string &description, int priority);

  // Virtual destructor for proper inheritance
  virtual ~Task();

  // Getters
  std::string get_title() const;
  std::string get_description() const;
  int get_priority() const;

  // Setters
  void set_title(const std::string &title);
  void set_description(const std::string &description);
  void set_priority(int priority);

  // Display task information (virtual for polymorphism)
  virtual void display() const;

  // Pure virtual method making this an abstract class
  virtual std::string get_type() const = 0;

private:
  std::string title;
  std::string description;
  int priority; // 1-5 scale, 5 being highest priority 1 lowest
};

// Assignment task - inherits from Task
class Assignment : public Task {
public:
  // Constructors
  Assignment();
  Assignment(const std::string &title, const std::string &description,
             int priority, const std::string &course,
             const std::string &due_date);

  // Additional getters
  std::string get_course() const;
  std::string get_due_date() const;

  // Additional setters
  void set_course(const std::string &course);
  void set_due_date(const std::string &due_date);

  // Override display method
  virtual void display() const override;

  // implementation of get_type
  virtual std::string get_type() const override;

private:
  std::string course;
  std::string due_date;
};

// Study Session task - inherits from Task
class StudySession : public Task {
public:

  // Constructors
  StudySession();
  StudySession(const std::string &title, const std::string &description,
               int priority, const std::string &subject, int duration_minutes);

  // Additional getters
  std::string get_subject() const;
  int get_duration() const;
  // Additional setters
  void set_subject(const std::string &subject);
  void set_duration(int duration_minutes);
  // Override display method
  virtual void display() const override;
  // Implementation of get_type
  virtual std::string get_type() const override;

private:
  std::string subject;
  int duration_minutes;
};


#endif