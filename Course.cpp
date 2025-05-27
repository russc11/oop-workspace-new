#include "Course.h"

Course::Course(int id, const std::string& name) : id(id), name(name) {}

void Course::addPerson(Person* p) { persons.push_back(p); }
std::vector<Person*> Course::get_persons() const { return persons; }

int Course::get_id() const { return id; }
std::string Course::get_name() const { return name; }