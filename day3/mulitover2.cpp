#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    long long ans = 0;
    string s;
    getline(cin, s);
    
    // Improved regex: Capture mul(x, y) directly using groups
    regex pattern(R"(do\(\)|don't\(\)|mul\((\d+),(\d+)\))");

    auto words_begin = sregex_iterator(s.begin(), s.end(), pattern);
    auto words_end = sregex_iterator();

    bool can_do = true;
    for (sregex_iterator it = words_begin; it != words_end; ++it) {
        string f = it->str();
        
        // If it's "don't()", disable multiplication
        if (f == "don't()") {
            can_do = false;
        }
        // If it's "do()", enable multiplication
        else if (f == "do()") {
            can_do = true;
        }
        // If it's a "mul(x, y)" and multiplication is enabled, process it
        else if (can_do) {
            // The groups are captured in the regex, so directly extract x and y
            long long x = stoll(it->str(1));  // Capture group 1 is the first number (x)
            long long y = stoll(it->str(2));  // Capture group 2 is the second number (y)
            ans += x * y;
        }
    }

    cout << ans << endl;
    return 0;
}
