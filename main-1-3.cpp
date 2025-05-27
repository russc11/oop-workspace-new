#include <iostream>
#include "University.h"
#include "Student.h"

int main() {
    University uni("My University", "City");

    uni.addCourse(1234, "OOP");

    Student seb("Seb", 1884670);
    auto courses = uni.get_courses();
    if (!courses.empty()) {
        courses[0].addPerson(&seb);
    }

    auto gradebook = uni.get_gradebook();
    gradebook->addGrade(1884670, 1234, "assign 1", 90);
    gradebook->addGrade(1884670, 1234, "assign 2", 85);
    gradebook->addGrade(1884670, 1234, "final", 95);
    
    return 0;
}