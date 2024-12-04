#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Directions to check in (row, col): right, left, down, up, diagonals
vector<pair<int, int>> directions = {
    {1, 1},   // Down-right (Diagonal)
    {-1, -1}, // Up-left (Diagonal)
    {1, -1},  // Down-left (Diagonal)
    {-1, 1}   // Up-right (Diagonal)
};
string word1 = "MAS" , word2 = "SAM";
bool bfs(int row, int col, vector<string>& grid) {
    int nr = row+1 , nc=col+1;
    int pr = row-1 , pc = col-1;

    if (pr < 0 || nr >= grid.size() ||  pc< 0 || nc >= grid[0].size()) {
             return 0;
            }
    string str1 ="" ,str2="";

    str1+=grid[pr][pc];
    str1+="A";
    str1+=grid[nr][nc];

    str2+=grid[pr][nc];
    str2+='A';
    str2+=grid[nr][pc];
    

    if((str1 ==word1 || str1 == word2)  && (str2 ==word1 || str2 == word2)){
        return true;
    }
    

    return false;
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
            
            if (grid[i][j] == 'A') {

                if(bfs(i , j , grid)){
                    ans++;
                }
                
            }
        }
    }
   cout<<ans<<endl;
    return 0;
}
