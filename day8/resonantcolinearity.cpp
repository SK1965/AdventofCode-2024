#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
    int part1(const vector<string>& data) {
        int rows = data.size();
        int cols = data[0].size();

        map<char, vector<pair<int, int>>> antennas;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (data[row][col] != '.') {
                    antennas[data[row][col]].emplace_back(row, col);
                }
            }
        }

        set<pair<int, int>> antinodes;
        for (const auto& [antenna, coords] : antennas) {
            for (size_t i = 0; i < coords.size(); ++i) {
                for (size_t j = i + 1; j < coords.size(); ++j) {
                    auto diff = make_tuple(coords[j].first - coords[i].first,
                                           coords[j].second - coords[i].second);

                    for (int _idx = 0; _idx < 2; ++_idx) {
                        int _dir = (_idx == 0) ? -1 : 1;
                        pair<int, int> pos = (_idx == 0) ? coords[i] : coords[j];

                        pos.first += _dir * get<0>(diff);
                        pos.second += _dir * get<1>(diff);

                        if (pos.first >= 0 && pos.first < rows && pos.second >= 0 && pos.second < cols) {
                            antinodes.insert(pos);
                        }
                    }
                }
            }
        }

        return antinodes.size();
    }

    int part2(const vector<string>& data) {
        int rows = data.size();
        int cols = data[0].size();

        map<char, vector<pair<int, int>>> antennas;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (data[row][col] != '.') {
                    antennas[data[row][col]].emplace_back(row, col);
                }
            }
        }

        set<pair<int, int>> antinodes;
        for (const auto& [antenna, coords] : antennas) {
            for (size_t i = 0; i < coords.size(); ++i) {
                for (size_t j = i + 1; j < coords.size(); ++j) {
                    auto diff = make_tuple(coords[j].first - coords[i].first,
                                           coords[j].second - coords[i].second);

                    // For each antenna pair, we will iterate in both directions along the calculated diff
                    for (int _idx = 0; _idx < 2; ++_idx) {
                        int _dir = (_idx == 0) ? -1 : 1;
                        pair<int, int> pos = (_idx == 0) ? coords[i] : coords[j];

                        // Traverse in the direction of the difference
                        while (pos.first >= 0 && pos.first < rows && pos.second >= 0 && pos.second < cols) {
                            antinodes.insert(pos);
                            pos.first += _dir * get<0>(diff);
                            pos.second += _dir * get<1>(diff);
                        }
                    }
                }
            }
        }

        return antinodes.size();
    }
};

int main() {
    ifstream input("input.txt");
    string line;
    vector<string> data;

    while (getline(input, line)) {
        data.push_back(line);
    }

    Solution solution;

    // Part 1
    cout << "Part 1 Result: " << solution.part1(data) << endl;

    // Part 2
    cout << "Part 2 Result: " << solution.part2(data) << endl;

    return 0;
}
