#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif

    int validSequences = 0;

    for(int idx = 0; idx < 1000; idx++) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream lineStream(line);
        std::vector<std::string> tokens;
        while(lineStream >> line) {
            tokens.push_back(line);
        }

        int increasingCount = 0, decreasingCount = 0;
        for(int j = 0; j < tokens.size() - 1; j++) {
            if(stoi(tokens[j]) < stoi(tokens[j+1])) increasingCount++;
            if(stoi(tokens[j]) > stoi(tokens[j+1])) decreasingCount++;
        }

        if(increasingCount != tokens.size() - 1 && decreasingCount != tokens.size() - 1) continue;

        bool isSafe = true;
        for(int j = 0; j < tokens.size() - 1; j++) {
            if(abs(stoi(tokens[j]) - stoi(tokens[j+1])) > 3) {
                isSafe = false;
                break;
            }
        }

        if(isSafe) {
            validSequences++;
        }
    }

    std::cout << validSequences << std::endl;
}
