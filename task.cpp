#include "task.h"

// Base Task Implementation
Task::Task() : title(""), description(""), priority(1) {}

Task::Task(const std::string &title, const std::string &description,
           int priority)
    : title(title), description(description), priority(priority) {}

Task::~Task() {}

std::string Task::get_title() const { return title; }

std::string Task::get_description() const { return description; }

int Task::get_priority() const { return priority; }

void Task::set_title(const std::string &title) { this->title = title; }

void Task::set_description(const std::string &description) {
  this->description = description;
}

void Task::set_priority(int priority) {
  if (priority < 1)
    priority = 1;
  if (priority > 5)
    priority = 5;
  this->priority = priority;
}

void Task::display() const {
  std::cout << "Title: " << title << std::endl;
  std::cout << "Description: " << description << std::endl;
  std::cout << "Priority: " << priority << " (1-5)" << std::endl;
}

// Assignment Implementation
Assignment::Assignment() : Task(), course(""), due_date("") {}

Assignment::Assignment(const std::string &title, const std::string &description,
                       int priority, const std::string &course,
                       const std::string &due_date)
    : Task(title, description, priority), course(course), due_date(due_date) {}

std::string Assignment::get_course() const { return course; }

std::string Assignment::get_due_date() const { return due_date; }

void Assignment::set_course(const std::string &course) {
  this->course = course;
}

void Assignment::set_due_date(const std::string &due_date) {
  this->due_date = due_date;
}

void Assignment::display() const {
  std::cout << "===== ASSIGNMENT =====" << std::endl;
  Task::display();
  std::cout << "Course: " << course << std::endl;
  std::cout << "Due Date: " << due_date << std::endl;
  std::cout << "======================" << std::endl;
}

std::string Assignment::get_type() const { return "Assignment"; }

// StudySession Implementation
StudySession::StudySession() : Task(), subject(""), duration_minutes(0) {}

StudySession::StudySession(const std::string &title,
                           const std::string &description, int priority,
                           const std::string &subject, int duration_minutes)
    : Task(title, description, priority), subject(subject),
      duration_minutes(duration_minutes) {}

std::string StudySession::get_subject() const { return subject; }

int StudySession::get_duration() const { return duration_minutes; }

void StudySession::set_subject(const std::string &subject) {
  this->subject = subject;
}

void StudySession::set_duration(int duration_minutes) {
  if (duration_minutes < 0)
    duration_minutes = 0;
  this->duration_minutes = duration_minutes;
}

void StudySession::display() const {
  std::cout << "===== STUDY SESSION =====" << std::endl;
  Task::display();
  std::cout << "Subject: " << subject << std::endl;
  std::cout << "Duration: " << duration_minutes << " minutes" << std::endl;
  std::cout << "=========================" << std::endl;
}

std::string StudySession::get_type() const { return "StudySession"; }