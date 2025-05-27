#include "Person.h"

Person::Person(const std::string& name) : name(name) {}
Person::~Person() {}
std::string Person::get_name() const { return name; }