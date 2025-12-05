#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;
const int INF = 2147483647;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>> q;
        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                if (rooms[i][j] == 0) {
                    q.push(make_pair(i, j));
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x > 0 && rooms[x-1][y] == INF)
                rooms[x-1][y] = rooms[x][y] + 1, q.push(make_pair(x - 1, y));
            if (y > 0 && rooms[x][y-1] == INF)
                rooms[x][y-1] = rooms[x][y] + 1, q.push(make_pair(x, y - 1));
            if (x < rooms.size() - 1 && rooms[x+1][y] == INF)
                rooms[x+1][y] = rooms[x][y] + 1, q.push(make_pair(x + 1, y));
            if (y < rooms[x].size() - 1 && rooms[x][y+1] == INF)
                rooms[x][y+1] = rooms[x][y] + 1, q.push(make_pair(x, y + 1));
        }
    }
};