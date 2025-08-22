#include <iostream>
#include "Person.h"

extern PersonList createPersonList(int n);
extern PersonList deepCopyPersonList(PersonList pl);

int main() {
  
    PersonList original = createPersonList(3);
    original.people[0].name = "Alice";
    original.people[0].age = 25;
   
    PersonList copy = deepCopyPersonList(original);
  
    original.people[0].name = "Bob";
    original.people[0].age = 30;
  
    std::cout << "Original first person: " << original.people[0].name 
              << ", " << original.people[0].age << std::endl;
    std::cout << "Copy first person: " << copy.people[0].name 
              << ", " << copy.people[0].age << std::endl;
    
    delete[] original.people;
    delete[] copy.people;
    return 0;
}