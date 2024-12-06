#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    vector<vector<char>> grid(130, vector<char>(130, '.'));

    pair<int, int> startPos;
    for (int row = 0; row < 130; row++) {
        for (int col = 0; col < 130; col++) {
            cin >> grid[row][col];
            if (grid[row][col] == '^') {
                startPos = {row, col};
            }
        }
    }

    int x = startPos.first;
    int y = startPos.second;

    vector<int> dirX = {0, 1, 0, -1};
    vector<int> dirY = {-1, 0, 1, 0};

    int direction = 3;
    int steps = 0;
    set<pair<int, int>> visited;
    visited.insert({x, y});
    grid[x][y] = 'X';

    while (true) {
        int newX = x + dirX[direction];
        int newY = y + dirY[direction];
        
        if (newX < 0 || newX >= 130 || newY < 0 || newY >= 130) {
            steps++;
            break;
        }

        if (grid[newX][newY] == '#') {
            direction = (direction == 0) ? 3 : direction - 1;
        }
        else {
            if (visited.find({newX, newY}) == visited.end()) {
                steps++;
            }
            visited.insert({newX, newY});
            grid[newX][newY] = 'X';
            x = newX;
            y = newY;
        }
    }

   

    cout << steps << endl;
}
