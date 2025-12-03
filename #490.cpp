#include<vector>
using namespace std;

class Solution {
public:
    bool DFS(vector<vector<int>>& maze, int x, int y, int tarX, int tarY) {
        if (tarX == x && tarY == y) return true;
        if (maze[x][y] == 2) return false;
        maze[x][y] = 2;
        if (x > 0 && maze[x-1][y] != 1) {
            int newP = x - 1;
            while (newP >= 0 && maze[newP][y] != 1) newP--;
            newP++;
            if (DFS(maze, newP, y, tarX, tarY)) return true;
        }
        if (y > 0 && maze[x][y-1] != 1) {
            int newP = y - 1;
            while (newP >= 0 && maze[x][newP] != 1) newP--;
            newP++;
            if (DFS(maze, x, newP, tarX, tarY)) return true;
        }
        if (x < maze.size() - 1 && maze[x+1][y] != 1) {
            int newP = x + 1;
            while (newP < maze.size() && maze[newP][y] != 1) newP++;
            newP--;
            if (DFS(maze, newP, y, tarX, tarY)) return true;
        }
        if (y < maze[x].size() - 1 && maze[x][y+1] != 1) {
            int newP = y + 1;
            while (newP < maze[x].size() && maze[x][newP] != 1) newP++;
            newP--;
            if (DFS(maze, x, newP, tarX, tarY)) return true;
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return DFS(maze, start[0], start[1], destination[0], destination[1]);
    }
};