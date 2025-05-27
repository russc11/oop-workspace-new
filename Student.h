#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person {
private:
    int id;
public:
    Student(const std::string& name, int id) : Person(name), id(id) {}
    int get_id() const { return id; }
};

#endif