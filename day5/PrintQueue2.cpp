#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

pair<unordered_map<int, unordered_set<int>>, vector<vector<int>>> extract_data(const vector<string>& data) {
    int _sep = find(data.begin(), data.end(), "") - data.begin();
    
    unordered_map<int, unordered_set<int>> rules;
    for (int i = 0; i < _sep; ++i) {
        stringstream ss(data[i]);
        int a, b;
        char separator;
        ss >> a >> separator >> b;
        rules[a].insert(b);
    }

    vector<vector<int>> updates;
    for (int i = _sep + 1; i < data.size(); ++i) {
        stringstream ss(data[i]);
        vector<int> update;
        string temp;
        while (getline(ss, temp, ',')) {
            update.push_back(stoi(temp));
        }
        updates.push_back(update);
    }

    return {rules, updates};
}

bool is_valid(const unordered_map<int, unordered_set<int>>& rules, const vector<int>& update) {
    for (int i = 0; i < update.size(); ++i) {
        for (int j = i + 1; j < update.size(); ++j) {
            if (rules.at(update[i]).count(update[j]) == 0) {
                return false;
            }
        }
    }
    return true;
}

vector<int> fix_update(const unordered_map<int, unordered_set<int>>& rules, const vector<int>& update) {
    unordered_map<int, unordered_set<int>> filtered_rules;
    for (int i : update) {
        for (int j : update) {
            if (rules.at(i).count(j)) {
                filtered_rules[i].insert(j);
            }
        }
    }

    vector<int> ordered_keys;
    for (const auto& p : filtered_rules) {
        ordered_keys.push_back(p.first);
    }
    sort(ordered_keys.begin(), ordered_keys.end(), 
         [&filtered_rules](int a, int b) {
             return filtered_rules.at(a).size() > filtered_rules.at(b).size();
         });

    return ordered_keys;
}

int part2(const vector<string>& data) {
    auto [rules, updates] = extract_data(data);
    int add_up = 0;

    for (const auto& update : updates) {
        if (!is_valid(rules, update)) {
            vector<int> fixed_update = fix_update(rules, update);
            add_up += fixed_update[update.size() / 2];
        }
    }

    return add_up;
}

int main() {
    ifstream infile("input.txt");
    
    if (!infile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    vector<string> lines;
    string line;
    
    while (getline(infile, line)) {
        lines.push_back(line);
    }

    cout << part2(lines) << endl;

    infile.close();
    return 0;
}
