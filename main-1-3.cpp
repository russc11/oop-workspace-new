#include <iostream>
#include "Person.h"

extern PersonList deepCopyPersonList(PersonList pl);

int main() {
    PersonList original;
    original.numPeople = 2;
    original.people = new Person[2];
    original.people[0] = {"Alice", 25};
    original.people[1] = {"Bob", 30};

    PersonList copy = deepCopyPersonList(original);
    
    original.people[0].name = "Modified";
    original.people[0].age = 99;

    std::cout << "Original first person: " << original.people[0].name << ", " << original.people[0].age << std::endl;
    std::cout << "Copy first person: " << copy.people[0].name << ", " << copy.people[0].age << std::endl;

    delete[] original.people;
    delete[] copy.people;
    
    return 0;
}