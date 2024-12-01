#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

using namespace std;
int main() {
    // Open the input file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1; 
    }

    string inp;
    vector<int> a;
    unordered_map<int, int> mymap;

    int i = 0;
    // Read input from the file
    while (getline(inputFile, inp)) {
        istringstream stream(inp);
        int num;
        while (stream >> num) {
            if (i % 2 == 0) {
                a.push_back(num); 
            } else {
                mymap[num]++; 
            }
            i++;
        }
    }

    inputFile.close();

    sort(a.begin(), a.end());

    long long count = 0;
    for (auto it : a) {
        count += (it * mymap[it]);
    }

    cout << count << endl;

    return 0;
}
