#include <iostream>
#include "Person.h"

extern PersonList createPersonList(int n);
extern PersonList shallowCopyPersonList(PersonList pl);

int main() {
    PersonList original = createPersonList(3);
    original.people[0].name = "Charlie";
    original.people[0].age = 28;
    
    PersonList copy = shallowCopyPersonList(original);
  
    original.people[0].name = "David";
    original.people[0].age = 32;
   
    std::cout << "Original first person: " << original.people[0].name 
              << ", " << original.people[0].age << std::endl;
    std::cout << "Copy first person: " << copy.people[0].name 
              << ", " << copy.people[0].age << std::endl;
    
    delete[] original.people; 
    return 0;
}