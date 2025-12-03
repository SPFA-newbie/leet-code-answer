#include<vector>
using namespace std;

typedef pair<int, int> Flag;

class Solution {
public:
    vector<vector<Flag>> graph;
    Flag find(Flag pos) {
        int x = pos.first, y = pos.second;
        if (graph[x][y] != make_pair(x, y))
            graph[x][y] = find(graph[x][y]);
        return graph[x][y];
    }
    bool vUnion(Flag a, Flag b) {
        if (find(a) == find(b)) return false;
        Flag pos = find(a);
        graph[pos.first][pos.second] = find(b);
        return true;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        graph.clear();
        for (int i = 0; i < m; i++) {
            vector<pair<int, int>> row;
            for (int j = 0; j < n; j++) {
                row.push_back(make_pair(-1, -1));
            }
            graph.push_back(row);
        }
        vector<int> ans;
        int num = 0;
        Flag water = make_pair(-1, -1);
        for (auto v: positions) {
            if (graph[v[0]][v[1]] != water) {
                ans.push_back(num);
                continue;
            }
            num++;
            graph[v[0]][v[1]] = make_pair(v[0], v[1]);
            if (v[0] > 0 && graph[v[0]-1][v[1]] != water) {
                if (vUnion(make_pair(v[0], v[1]), make_pair(v[0] - 1, v[1])))
                    num--;
            }
            if (v[1] > 0 && graph[v[0]][v[1]-1] != water) {
                if (vUnion(make_pair(v[0], v[1]), make_pair(v[0], v[1] - 1)))
                    num--;
            }
            if (v[0] < m - 1 && graph[v[0]+1][v[1]] != water) {
                if (vUnion(make_pair(v[0], v[1]), make_pair(v[0] + 1, v[1])))
                    num--;
            }
            if (v[1] < n - 1 && graph[v[0]][v[1]+1] != water) {
                if (vUnion(make_pair(v[0], v[1]), make_pair(v[0], v[1] + 1)))
                    num--;
            }
            ans.push_back(num);
        }
        return ans;
    }
};