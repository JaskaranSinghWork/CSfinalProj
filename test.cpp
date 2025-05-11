
#include <iostream>
#include <cassert>
#include <string>
#include "task.h"
#include "task_manager.h"
#include "study_timer.h"

// Function to print test results
void print_test_result(const std::string& test_name, bool passed) {
    std::cout << test_name << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test Assignment class
void test_assignment() {
    std::cout << "\n=== Testing Assignment Class ===" << std::endl;

    Assignment assignment("Math Homework", "Complete exercises 1-10", 3, "MATH101", "2025-05-15");

    bool test1 = (assignment.get_title() == "Math Homework");
    print_test_result("Assignment title", test1);

    bool test2 = (assignment.get_description() == "Complete exercises 1-10");
    print_test_result("Assignment description", test2);

    bool test3 = (assignment.get_priority() == 3);
    print_test_result("Assignment priority", test3);

    bool test4 = (assignment.get_course() == "MATH101");
    print_test_result("Assignment course", test4);

    bool test5 = (assignment.get_due_date() == "2025-05-15");
    print_test_result("Assignment due date", test5);

    bool test6 = (assignment.get_type() == "Assignment");
    print_test_result("Assignment type", test6);

    // Test setters
    assignment.set_title("Updated Math Homework");
    bool test7 = (assignment.get_title() == "Updated Math Homework");
    print_test_result("Assignment set_title", test7);

    assignment.set_priority(5);
    bool test8 = (assignment.get_priority() == 5);
    print_test_result("Assignment set_priority", test8);
}

// Test StudySession class
void test_study_session() {
    std::cout << "\n=== Testing StudySession Class ===" << std::endl;

    StudySession session("Physics Review", "Review chapters 3-5", 4, "Physics", 90);

    bool test1 = (session.get_title() == "Physics Review");
    print_test_result("StudySession title", test1);

    bool test2 = (session.get_description() == "Review chapters 3-5");
    print_test_result("StudySession description", test2);

    bool test3 = (session.get_priority() == 4);
    print_test_result("StudySession priority", test3);

    bool test4 = (session.get_subject() == "Physics");
    print_test_result("StudySession subject", test4);

    bool test5 = (session.get_duration() == 90);
    print_test_result("StudySession duration", test5);

    bool test6 = (session.get_type() == "StudySession");
    print_test_result("StudySession type", test6);

    // Test setters
    session.set_subject("Advanced Physics");
    bool test7 = (session.get_subject() == "Advanced Physics");
    print_test_result("StudySession set_subject", test7);

    session.set_duration(120);
    bool test8 = (session.get_duration() == 120);
    print_test_result("StudySession set_duration", test8);
}

// Test TaskManager class
void test_task_manager() {
    std::cout << "\n=== Testing TaskManager Class ===" << std::endl;

    TaskManager manager;

    // Test initial state
    bool test1 = (manager.get_task_count() == 0);
    print_test_result("TaskManager initial count", test1);

    // Test adding tasks
    manager.add_assignment("CS Assignment", "Programming project", 4, "CS202", "2025-05-20");
    manager.add_study_session("Java Study", "Practice Java basics", 2, "Java Programming", 60);

    bool test2 = (manager.get_task_count() == 2);
    print_test_result("TaskManager add tasks", test2);

    // Test saving and loading
    bool test3 = manager.save_to_file("test_tasks.txt");
    print_test_result("TaskManager save to file", test3);

    // Create a new manager and load from file
    TaskManager manager2;
    bool test4 = manager2.load_from_file("test_tasks.txt");
    print_test_result("TaskManager load from file", test4);

    bool test5 = (manager2.get_task_count() == 2);
    print_test_result("TaskManager loaded task count", test5);

    // Test removing a task
    bool test6 = manager.remove_task(0);
    print_test_result("TaskManager remove task", test6);

    bool test7 = (manager.get_task_count() == 1);
    print_test_result("TaskManager count after remove", test7);
}

// Test StudyTimer class
void test_study_timer() {
    std::cout << "\n=== Testing StudyTimer Class ===" << std::endl;

    StudyTimer timer;

    // Test initial state
    bool test1 = (!timer.is_running());
    print_test_result("StudyTimer initial state", test1);

    bool test2 = (timer.get_total_time() == 0);
    print_test_result("StudyTimer initial total time", test2);

    // We cant easily test the actual timing functionality without delays so we will just check that the methods dont crash
    timer.start("Math");

    bool test3 = (timer.is_running());
    print_test_result("StudyTimer running state", test3);

    bool test4 = (timer.get_current_subject() == "Math");
    print_test_result("StudyTimer current subject", test4);

    // Stop the timer
    timer.stop();

    bool test5 = (!timer.is_running());
    print_test_result("StudyTimer stopped state", test5);
}

void run_tests() {
    std::cout << "===== RUNNING TESTS =====" << std::endl;

    test_assignment();
    test_study_session();
    test_task_manager();
    test_study_timer();

    std::cout << "\nAll tests completed." << std::endl;
}

#ifdef TESTING
int main() {
    run_tests();
    return 0;
}
#endif
