#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Directions to check in (row, col): right, left, down, up, diagonals
vector<pair<int, int>> directions = {
    {0, 1},   // Right
    {0, -1},  // Left
    {1, 0},   // Down
    {-1, 0},  // Up
    {1, 1},   // Down-right (Diagonal)
    {-1, -1}, // Up-left (Diagonal)
    {1, -1},  // Down-left (Diagonal)
    {-1, 1}   // Up-right (Diagonal)
};
string word = "XMAS";
int bfs(int row, int col, vector<string>& grid) {
    int count = 0;
  
    for (int i = 0; i < 8; i++) {
        string temp = "X"; 

        
        int dr = row, dc = col;
        bool valid = true;

        
        for (int j = 1; j < 4; j++) {
            dr += directions[i].first;
            dc += directions[i].second;
            if (dr < 0 || dr >= grid.size() || dc < 0 || dc >= grid[0].size()) {
                valid = false;
                break;
            }

            temp += grid[dr][dc]; 
        }

        if (valid && temp == word) {
            count++;
        }
    }

    return count;
}

int main() {
    // Vector to store each line of the file (grid)
    vector<string> grid;
    string line;

    // Read the file
    ifstream inputFile("input.txt");

    // Check if the file opened successfully
    if (!inputFile.is_open()) {
        cerr << "Could not open the file!" << endl;
        return 1;
    }

    // Read each line and add to the grid
    while (getline(inputFile, line)) {
        grid.push_back(line);
    }

    // Close the file
    inputFile.close();

    int rows = grid.size();
    int cols = grid[0].size();


   int ans =0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            
            if (grid[i][j] == 'X') {

                ans+=bfs(i , j , grid);
                
            }
        }
    }
   cout<<ans<<endl;
    return 0;
}
