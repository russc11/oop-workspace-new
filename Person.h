#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
    std::string name;
public:
    Person(const std::string& name) : name(name) {}
    virtual ~Person() {}
    std::string get_name() const { return name; }
};

#endif