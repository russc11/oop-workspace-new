#ifndef GRADEBOOK_H
#define GRADEBOOK_H

#include <vector>
#include "Grade.h"

class Gradebook {
private:
    std::vector<Grade> grades;
public:
    void addGrade(int stud_id, int course_id, const std::string& assignment, int value) {
        grades.emplace_back(stud_id, course_id, assignment, value);
    }
    
    std::vector<Grade> get_grades() const { return grades; }
};

#endif