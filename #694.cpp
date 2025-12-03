#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>>& grid, int x, int y, string& hash) {
        grid[x][y] = 2;
        if (x > 0) {
            switch (grid[x-1][y]) {
                case 0:
                    hash.push_back('a'); break;
                case 2:
                    hash.push_back('b'); break;
                case 1:
                    hash.push_back('c');
                    DFS(grid, x - 1, y, hash);
                    break;
            }
        } else {
            hash.push_back('a');
        }
        hash.push_back('d');
        if (y > 0) {
            switch (grid[x][y-1]) {
                case 0:
                    hash.push_back('e'); break;
                case 2:
                    hash.push_back('f'); break;
                case 1:
                    hash.push_back('g');
                    DFS(grid, x, y - 1, hash);
                    break;
            }
        } else {
            hash.push_back('e');
        }
        hash.push_back('h');
        if (x < grid.size() - 1) {
            switch (grid[x+1][y]) {
                case 0:
                    hash.push_back('A'); break;
                case 2:
                    hash.push_back('B'); break;
                case 1:
                    hash.push_back('C');
                    DFS(grid, x + 1, y, hash);
                    break;
            }
        } else {
            hash.push_back('A');
        }
        hash.push_back('D');
        if (y < grid[x].size() - 1) {
            switch (grid[x][y+1]) {
                case 0:
                    hash.push_back('E'); break;
                case 2:
                    hash.push_back('F'); break;
                case 1:
                    hash.push_back('G');
                    DFS(grid, x, y + 1, hash);
                    break;
            }
        } else {
            hash.push_back('E');
        }
        hash.push_back('H');
    }
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islandHash;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == 1) {
                    string hash = "";
                    DFS(grid, i, j, hash);
                    islandHash.insert(hash);
                }
        return islandHash.size();
    }
};