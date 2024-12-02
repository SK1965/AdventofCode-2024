#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_set>

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int validSequences = 0;

    for(int index = 0; index < 1000; index++) {
        std::string line;
        std::getline(std::cin, line);
        std::istringstream lineStream(line);
        std::vector<int> numbers;
        while(lineStream >> line) {
            numbers.push_back(stoi(line));
        }

        int left = 0, right = 1;

        int firstIdx = -1, secondIdx = -1;
        int flag = 0;
        
        // First iteration: Check the condition for valid pairs (arr[k] - arr[j] <= 3)
        while(right < numbers.size()) {
            if((numbers[right] - numbers[left] <= 3 && numbers[right] - numbers[left] > 0)) {
                left++;
                right++;
                continue;
            }

            if(firstIdx != -1) {
                flag = 2;
                break;
            }
            firstIdx = left;
            secondIdx = right;

            left += 2;
            right += 2;
        }

        if(firstIdx == -1 && flag != 2) {
            validSequences++;
            continue;
        }

        if(flag != 2) {
            left = firstIdx;
            right = secondIdx;
            std::vector<int> groupA, groupB;

            // Create two separate groups excluding the invalid pairs
            for(int idx = 0; idx < numbers.size(); idx++) {
                if(idx != left) {
                    groupA.push_back(numbers[idx]);
                }
                if(idx != right) {
                    groupB.push_back(numbers[idx]);
                }
            }

            int check = 0;
            for(int i = 0; i < groupA.size() - 1; i++) {
                if(groupA[i + 1] - groupA[i] > 3 || groupA[i + 1] - groupA[i] <= 0) {
                    check++;
                    break;
                }
            }

            for(int i = 0; i < groupB.size() - 1; i++) {
                if(groupB[i + 1] - groupB[i] > 3 || groupB[i + 1] - groupB[i] <= 0) {
                    check++;
                    break;
                }
            }

            if(check < 2) {
                validSequences++;
                continue;
            }
        }

        left = 0;
        right = 1;
        flag = 0;
        firstIdx = -1;
        secondIdx = -1;
        
        // Second iteration: Check the condition for valid pairs (arr[j] - arr[k] <= 3)
        while(right < numbers.size()) {
            if((numbers[left] - numbers[right] <= 3 && numbers[left] - numbers[right] > 0)) {
                left++;
                right++;
                continue;
            }

            if(firstIdx != -1) {
                flag = 2;
                break;
            }
            firstIdx = left;
            secondIdx = right;

            left += 2;
            right += 2;
        }

        if(firstIdx == -1 && flag != 2) {
            validSequences++;
            continue;
        }

        if(flag != 2) {
            left = firstIdx;
            right = secondIdx;
            std::vector<int> groupA, groupB;

            // Create two separate groups excluding the invalid pairs
            for(int idx = 0; idx < numbers.size(); idx++) {
                if(idx != left) {
                    groupA.push_back(numbers[idx]);
                }
                if(idx != right) {
                    groupB.push_back(numbers[idx]);
                }
            }

            int check = 0;
            for(int i = 0; i < groupA.size() - 1; i++) {
                if(groupA[i] - groupA[i + 1] > 3 || groupA[i] - groupA[i + 1] <= 0) {
                    check++;
                    break;
                }
            }

            for(int i = 0; i < groupB.size() - 1; i++) {
                if(groupB[i] - groupB[i + 1] > 3 || groupB[i] - groupB[i + 1] <= 0) {
                    check++;
                    break;
                }
            }

            if(check < 2) {
                validSequences++;
                continue;
            }
        }
    }

    std::cout << validSequences << std::endl;
}
