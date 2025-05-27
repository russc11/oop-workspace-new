#ifndef COURSE_H
#define COURSE_H

#include <vector>
#include "Person.h"

class Course {
private:
    std::string name;
    int id;
    std::vector<Person*> persons;
public:
    Course(int id, const std::string& name) : id(id), name(name) {}
    
    void addPerson(Person* p) { persons.push_back(p); }
    std::vector<Person*> get_persons() const { return persons; }
    
    int get_id() const { return id; }
    std::string get_name() const { return name; }
};

#endif