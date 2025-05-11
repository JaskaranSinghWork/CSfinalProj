#ifndef STUDY_TIMER_H
#define STUDY_TIMER_H

#include <ctime>
#include <string>
#include <vector>

// StudyTimer class - tracks study time for subjects
class StudyTimer {
public:
  // Constructor
  StudyTimer();

  // Start timer for a subject
  void start(const std::string &subject);

  // Stop timer and record time spent
  void stop();

  // Get total time studied for a subject (in seconds)
  int get_time_for_subject(const std::string &subject) const;

  // Get total time studied overall (in seconds)
  int get_total_time() const;

  // Display summary of time spent on each subject
  void display_summary() const;

  // Check if timer is running
  bool is_running() const;

  // Get current subject being studied
  std::string get_current_subject() const;

private:
  struct TimeRecord {
    std::string subject;
    int seconds;
    TimeRecord(const std::string &s, int t) : subject(s), seconds(t) {}
  };

  std::vector<TimeRecord> time_records;
  std::string current_subject;
  time_t start_time;
  bool timer_running;
};

#endif 