#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    // Vector to store each line of the file
    std::vector<std::string> lines;
    
    // Open the file
    std::ifstream inputFile("input.txt");
    
    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Could not open the file!" << std::endl;
        return 1;
    }
    
    std::string line;
    // Read each line from the file and push it into the vector
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    
    // Close the file
    inputFile.close();
    
    // Output the vector contents
    std::cout << "Contents of the file stored in the vector: \n";
    for (const auto& str : lines) {
        std::cout << str << std::endl;
    }
    
    return 0;
}
