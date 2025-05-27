#include "University.h"

University::University(const std::string& name, const std::string& location)
    : name(name), location(location), gradebook(new Gradebook()) {}

University::~University() { delete gradebook; }

void University::addCourse(int id, const std::string& name) {
    courses.emplace_back(id, name);
}

Gradebook* University::get_gradebook() { return gradebook; }
std::vector<Course> University::get_courses() { return courses; }