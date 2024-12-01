#include <bits/stdc++.h>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    ifstream inputFile("input.txt"); 
    if (!inputFile) { 
        cerr << "Error opening file!" << endl;
        return 1; 
    }

    string inp;
    vector<int> a;
    vector<int> b;

   
    while (getline(inputFile, inp)) {
        istringstream stream(inp);
        int num;
        bool is_a = true;  
        while (stream >> num) {
            if (is_a)
                a.push_back(num);
            else
                b.push_back(num);

            is_a = !is_a;  
        }
    }

    
    inputFile.close();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long count = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        count += abs(a[i] - b[i]);
    }

    cout << count << endl;
    return 0;
}
