#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <climits>

int read(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    try {
        int sum = 0;
        std::string line;
        int lineNumber = 0;

        while (std::getline(file, line)) {
            lineNumber++;
            if (line.empty()) continue; 

            try {
                size_t pos;
                long num = std::stol(line, &pos);

                if (pos != line.length()) {
                    throw std::invalid_argument("Invalid characters in number");
                }

                if (num > INT_MAX || num < INT_MIN) {
                    throw std::out_of_range("Number out of int range");
                }

                sum += static_cast<int>(num);
            } 
            catch (const std::invalid_argument& e) {
                std::cerr << "invalid_argument error" << std::endl;
                throw; 
            } 
            catch (const std::out_of_range& e) {
                std::cerr << "out_of_range error" << std::endl;
                throw; 
            }
        }

        file.close();
        return sum;
    } 
    catch (...) {
        if (file.is_open()) {
            file.close();
        }
        throw; 
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    try {
        int total = read(argv[1]);
        std::cout << total << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}