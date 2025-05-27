#include <iostream>
#include "University.h"
#include "Gradebook.h"

int main() {
    University uni("My University", "City");

    uni.get_gradebook()->addGrade(1884670, 1234, "assign 1", 90);

    auto grades = uni.get_gradebook()->get_grades();
    for (const auto& g : grades) {
        std::cout << "Student ID: " << g.get_student_id() << "\n";
        std::cout << "Course ID: " << g.get_course_id() << "\n";
        std::cout << "Assignment: " << g.get_assignment() << "\n";
        std::cout << "Value: " << g.get_value() << "\n";
    }
    
    return 0;
}