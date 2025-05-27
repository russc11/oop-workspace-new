#ifndef GRADE_H
#define GRADE_H

#include <string>

class Grade {
private:
    int student_id;
    int course_id;
    std::string assignment;
    int value;
public:
    Grade(int stud_id, int course_id, const std::string& assignment, int value)
        : student_id(stud_id), course_id(course_id), assignment(assignment), value(value) {}
    
    int get_student_id() const { return student_id; }
    int get_course_id() const { return course_id; }
    std::string get_assignment() const { return assignment; }
    int get_value() const { return value; }
};

#endif