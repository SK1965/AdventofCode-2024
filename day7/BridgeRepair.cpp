#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
using namespace std;

class Solution {
public:
    // Part 1: Only "+" and "*" operations
    long long part1(const vector<string>& data) {
        vector<pair<long long, vector<long long>>> equations;
        for (const string& line : data) {
            long long test_value;
            vector<long long> numbers;
            parseInput(line, test_value, numbers);
            equations.emplace_back(test_value, numbers);
        }

        long long result = 0;
        for (auto& [test_value, numbers] : equations) {
            if (canReachTargetPart1(test_value, numbers)) {
                result += test_value;
            }
        }

        return result;
    }

    // Part 2: Includes "+", "*", and concatenation
    long long part2(const vector<string>& data) {
        vector<pair<long long, vector<long long>>> equations;
        for (const string& line : data) {
            long long test_value;
            vector<long long> numbers;
            parseInput(line, test_value, numbers);
            equations.emplace_back(test_value, numbers);
        }

        long long result = 0;
        for (auto& [test_value, numbers] : equations) {
            if (canReachTargetPart2(test_value, numbers)) {
                result += test_value;
            }
        }

        return result;
    }

private:
    // Parse input line into test_value and numbers
    void parseInput(const string& line, long long& test_value, vector<long long>& numbers) {
        stringstream ss(line);
        string left, right;
        getline(ss, left, ':');
        getline(ss, right);
        test_value = stoll(left);  // Use stoll for long long
        stringstream nums(right);
        long long num;
        while (nums >> num) {
            numbers.push_back(num);
        }
    }

    // Helper for part1: Can we reach the target with "+" and "*"?
    bool canReachTargetPart1(long long target, vector<long long> numbers) {
        set<long long> possibles = {numbers[0]};
        for (size_t i = 1; i < numbers.size(); ++i) {
            long long curr = numbers[i];
            set<long long> next_possibles;
            for (long long p : possibles) {
                next_possibles.insert(p + curr);
                next_possibles.insert(p * curr);
            }
            possibles = move(next_possibles);
        }
        return possibles.count(target) > 0;
    }

    // Helper for part2: Can we reach the target with "+", "*", and concatenation?
    bool canReachTargetPart2(long long target, vector<long long> numbers) {
        set<long long> possibles = {numbers[0]};
        for (size_t i = 1; i < numbers.size(); ++i) {
            long long curr = numbers[i];
            set<long long> next_possibles;
            for (long long p : possibles) {
                vector<long long> next_values = {
                    p + curr,
                    p * curr,
                    stoll(to_string(p) + to_string(curr))  // Use stoll for concatenation
                };
                for (long long v : next_values) {
                    if (v <= target) {
                        next_possibles.insert(v);
                    }
                }
            }
            possibles = move(next_possibles);
        }
        return possibles.count(target) > 0;
    }
};

int main() {
    // Open the input file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input.txt" << endl;
        return 1;
    }

    // Read data from the file
    vector<string> data;
    string line;
    while (getline(inputFile, line)) {
        data.push_back(line);
    }
    inputFile.close();

    // Solve using the Solution class
    Solution solution;
    cout << "Part 1 Result: " << solution.part1(data) << endl;
    cout << "Part 2 Result: " << solution.part2(data) << endl;

    return 0;
}
