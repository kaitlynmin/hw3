#include <iostream>
#include <fstream>
#include "circuit.h"

int main() {
    Circuit circuit;

    // Load the circuit from a file
    if (!circuit.parse("single_not.txt")) {
        std::cerr << "Error: Unable to parse input file." << std::endl;
        return 1;
    }

    // Run the circuit and print output until a segmentation fault occurs
    std::ofstream output_file("output.txt");
    while (true) {
        // Check for segmentation fault before advancing
        if (!circuit.advance(output_file)) {
            std::cerr << "Error: Segmentation fault occurred." << std::endl;
            return 1;
        }
    }

    return 0;
}
