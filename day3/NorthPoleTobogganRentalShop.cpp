#include <bits/stdc++.h>
#include <regex>

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    std::string line;
    std::getline(std::cin, line);
    
    // Regex to match "mul(x, y)" format
    std::regex mulPattern(R"(mul\((\d+),\s*(\d+)\))");
    std::smatch match;
    
    std::string::const_iterator searchStart(line.cbegin());

    int ans=0;
    while (std::regex_search(searchStart, line.cend(), match, mulPattern)) {
        // match[1] is the first number (x)
        // match[2] is the second number (y)
        ans+=(stoi(match[1])* stoi(match[2]));
        searchStart = match.suffix().first;
    }

    std::cout<<ans<<std::endl;
    return 0;
}
