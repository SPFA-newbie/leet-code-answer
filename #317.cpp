#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

class Solution {
public:
    inline bool check(vector<vector<int>>& grid, vector<vector<bool>>& arr, int x, int y) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() && grid[x][y] == 0 && arr[x][y] != true;
    }
    void BFS(vector<vector<int>>& grid, vector<vector<int>>& dis, vector<vector<int>>& arr, int sx, int sy) {
        queue<pair<int, int>> q;
        vector<vector<int>> nowDis;
        vector<vector<bool>> nowArr;
        for (int i = 0; i < grid.size(); i++) {
            nowDis.push_back(vector<int>());
            nowArr.push_back(vector<bool>());
            for (int j = 0; j < grid[i].size(); j++) {
                nowDis[i].push_back(0);
                nowArr[i].push_back(false);
            }
        }
        q.push(make_pair(sx, sy));
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (check(grid, nowArr, x - 1, y)) {
                q.push(make_pair(x - 1, y));
                nowArr[x-1][y] = true;
                arr[x-1][y]++;
                nowDis[x-1][y] = nowDis[x][y] + 1;
                dis[x-1][y] += nowDis[x-1][y];
            }
            if (check(grid, nowArr, x + 1, y)) {
                q.push(make_pair(x + 1, y));
                nowArr[x+1][y] = true;
                arr[x+1][y]++;
                nowDis[x+1][y] = nowDis[x][y] + 1;
                dis[x+1][y] += nowDis[x+1][y];
            }
            if (check(grid, nowArr, x, y - 1)) {
                q.push(make_pair(x, y - 1));
                nowArr[x][y-1] = true;
                arr[x][y-1]++;
                nowDis[x][y-1] = nowDis[x][y] + 1;
                dis[x][y-1] += nowDis[x][y-1];
            }
            if (check(grid, nowArr, x, y + 1)) {
                q.push(make_pair(x, y + 1));
                nowArr[x][y+1] = true;
                arr[x][y+1]++;
                nowDis[x][y+1] = nowDis[x][y] + 1;
                dis[x][y+1] += nowDis[x][y+1];
            }
        }
        int mm = 0;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        vector<vector<int>> dis, arr;
        for (int i = 0; i < grid.size(); i++) {
            dis.push_back(vector<int>());
            arr.push_back(vector<int>());
            for (int j = 0; j < grid[i].size(); j++) {
                dis[i].push_back(0);
                arr[i].push_back(0);
            }
        }
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    count++;
                    BFS(grid, dis, arr, i, j);
                }
            }
        }
        int ans = 1e8;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 0) {
                    if (ans > dis[i][j] && arr[i][j] == count) ans = dis[i][j];
                }
            }
        }
        if (ans == 1e8) return -1;
        return ans;
    }
};