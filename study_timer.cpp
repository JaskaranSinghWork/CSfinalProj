#include "study_timer.h"
#include <iomanip>
#include <iostream>

StudyTimer::StudyTimer()
    : current_subject(""), start_time(0), timer_running(false) {}

void StudyTimer::start(const std::string &subject) {
  if (timer_running) {
    std::cout << "Error: Timer is already running for " << current_subject
              << std::endl;
    return;
  }

  current_subject = subject;
  start_time = time(nullptr);
  timer_running = true;
  std::cout << "Timer started for " << subject << std::endl;
}

void StudyTimer::stop() {
  if (!timer_running) {
    std::cout << "Error: No timer is currently running." << std::endl;
    return;
  }

  time_t end_time = time(nullptr);
  int seconds_elapsed = static_cast<int>(difftime(end_time, start_time));

  // Add to existing record or create new one
  bool found = false;
  for (TimeRecord &record : time_records) {
    if (record.subject == current_subject) {
      record.seconds += seconds_elapsed;
      found = true;
      break;
    }
  }

  if (!found) {
    time_records.push_back(TimeRecord(current_subject, seconds_elapsed));
  }

  // Format time for display
  int hours = seconds_elapsed / 3600;
  int minutes = (seconds_elapsed % 3600) / 60;
  int seconds = seconds_elapsed % 60;
  std::cout << "Timer stopped for " << current_subject << std::endl;
  std::cout << "Time studied: " << hours << "h " << minutes << "m " << seconds<< "s" << std::endl;
  timer_running = false;
  current_subject = "";
}

int StudyTimer::get_time_for_subject(const std::string &subject) const {
  for (const TimeRecord &record : time_records) {
    if (record.subject == subject) {
      return record.seconds;
    }
  }
  return 0;
}

int StudyTimer::get_total_time() const {
  int total = 0;
  for (const TimeRecord &record : time_records) {
    total += record.seconds;
  }
  return total;
}

void StudyTimer::display_summary() const {
  if (time_records.empty()) {
    std::cout << "No study time recorded yet." << std::endl;
    return;
  }

  std::cout << "\n===== STUDY TIME SUMMARY =====\n" << std::endl;
  int total_seconds = 0;

  for (const TimeRecord &record : time_records) {
    int hours = record.seconds / 3600;
    int minutes = (record.seconds % 3600) / 60;
    int seconds = record.seconds % 60;

    std::cout << std::left << std::setw(15) << record.subject << ": "
              << std::right << std::setw(2) << hours << "h " << std::setw(2)
              << minutes << "m " << std::setw(2) << seconds << "s" << std::endl;

    total_seconds += record.seconds;
  }

  int total_hours = total_seconds / 3600;
  int total_minutes = (total_seconds % 3600) / 60;
  int total_remaining_seconds = total_seconds % 60;

  std::cout << "\nTotal study time: " << total_hours << "h " << total_minutes
            << "m " << total_remaining_seconds << "s" << std::endl;
  std::cout << "=============================" << std::endl;
}

bool StudyTimer::is_running() const { 
    return timer_running; }

std::string StudyTimer::get_current_subject() const { 
    return current_subject; }