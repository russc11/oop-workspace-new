#include <iostream>
#include "Person.h"

extern PersonList shallowCopyPersonList(PersonList pl);

int main() {
    PersonList original;
    original.numPeople = 2;
    original.people = new Person[2];
    original.people[0] = {"Charlie", 40};
    original.people[1] = {"Dana", 35};
    

    PersonList copy = shallowCopyPersonList(original);

    original.people[0].name = "Changed";
    original.people[0].age = 100;

    std::cout << "Original first person: " << original.people[0].name << ", " << original.people[0].age << std::endl;
    std::cout << "Copy first person: " << copy.people[0].name << ", " << copy.people[0].age << std::endl;

    delete[] original.people;
    
    return 0;
}