#include <iostream>
#include "Musician.h"

int main() {
    Musician m1;
    std::cout << "Default musician - Instrument: " << m1.get_instrument() 
              << ", Experience: " << m1.get_experience() << " years" << std::endl;

    Musician m2("Violin", 5);
    std::cout << "Musician 2 - Instrument: " << m2.get_instrument() 
              << ", Experience: " << m2.get_experience() << " years" << std::endl;

    Musician m3("Piano", 10);
    std::cout << "Musician 3 - Instrument: " << m3.get_instrument() 
              << ", Experience: " << m3.get_experience() << " years" << std::endl;
    
    return 0;
}