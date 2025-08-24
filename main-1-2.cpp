#include <iostream>
#include "Orchestra.h"
#include "Musician.h"

int main() {
    Orchestra orchestra(3);

    Musician m1("Violin", 5);
    Musician m2("Cello", 7);
    Musician m3("Flute", 3);
    Musician m4("Trumpet", 4); // This one won't fit

    std::cout << "Adding m1 (Violin): " << (orchestra.add_musician(m1) ? "Success" : "Failed") << std::endl;
    std::cout << "Adding m2 (Cello): " << (orchestra.add_musician(m2) ? "Success" : "Failed") << std::endl;
    std::cout << "Adding m3 (Flute): " << (orchestra.add_musician(m3) ? "Success" : "Failed") << std::endl;
    std::cout << "Adding m4 (Trumpet): " << (orchestra.add_musician(m4) ? "Success" : "Failed") << std::endl;

    std::cout << "Current members: " << orchestra.get_current_number_of_members() << std::endl;

    std::cout << "Has Violin: " << (orchestra.has_instrument("Violin") ? "Yes" : "No") << std::endl;
    std::cout << "Has Trumpet: " << (orchestra.has_instrument("Trumpet") ? "Yes" : "No") << std::endl;
    
    return 0;
}