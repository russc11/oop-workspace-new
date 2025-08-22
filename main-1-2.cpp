#include <iostream>
#include "Person.h"

extern PersonList createPersonList(int n);

int main() {
    int n = 4;
    PersonList list = createPersonList(n);
    
    for (int i = 0; i < list.numPeople; i++) {
        std::cout << "Person " << i << ": " << list.people[i].name 
                  << ", " << list.people[i].age << std::endl;
    }
    
    delete[] list.people;
    return 0;
}