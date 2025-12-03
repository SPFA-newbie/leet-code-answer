#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        queue<pair<int, int>> q;
        vector<vector<int>> g;
        vector<int> deg;
        for (int i = 0; i < n; i++) {
            g.push_back(vector<int>());
            deg.push_back(0);
        }
        for (auto v: relations) {
            g[v[0]-1].push_back(v[1]-1);
            deg[v[1]-1]++;
        }
        int now = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) {
                end++;
                q.push(make_pair(i, now + 1));
            }
        }
        while (!q.empty()) {
            now = q.front().second;
            int pos = q.front().first;
            q.pop();
            for (auto i: g[pos]) {
                deg[i]--;
                if (deg[i] == 0) {
                    q.push(make_pair(i, now + 1));
                    end++;
                }
            }
        }
        if (end != n) return -1;
        return now;
        
    }
};