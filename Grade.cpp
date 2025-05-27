#include "Grade.h"

Grade::Grade(int stud_id, int course_id, const std::string& assignment, int value)
    : student_id(stud_id), course_id(course_id), assignment(assignment), value(value) {}

int Grade::get_student_id() const { return student_id; }
int Grade::get_course_id() const { return course_id; }
std::string Grade::get_assignment() const { return assignment; }
int Grade::get_value() const { return value; }