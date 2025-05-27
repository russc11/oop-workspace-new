#include "Gradebook.h"

void Gradebook::addGrade(int stud_id, int course_id, const std::string& assignment, int value) {
    grades.emplace_back(stud_id, course_id, assignment, value);
}

std::vector<Grade> Gradebook::get_grades() const { return grades; }