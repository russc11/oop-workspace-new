#include <iostream>
#include "Student.h"
#include "Instructor.h"
#include "Course.h"

int main() {
    Student seb("Seb", 1884670);

    Instructor drv("Dr.V");

    Course oop(1234, "OOP");
    oop.addPerson(&seb);
    oop.addPerson(&drv);

    auto persons = oop.get_persons();
    for (auto p : persons) {
        if (auto s = dynamic_cast<Student*>(p)) {
            std::cout << "Name of student: " << s->get_name() << "\n";
            std::cout << "Id of student: " << s->get_id() << "\n";
        } else if (auto i = dynamic_cast<Instructor*>(p)) {
            std::cout << "Name of instructor: " << i->get_name() << "\n";
        }
    }
    
    return 0;
}