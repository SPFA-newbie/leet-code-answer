#include<vector>
using namespace std;

class Solution {
public:
    vector<int> v;
    int find(int x) {
        if (v[x] != x)
            v[x] = find(v[x]);
        return v[x];
    }
    void vUnion(int a, int b) {
        v[find(a)] = find(b);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        v.clear();
        for (int i = 0; i < n; i++) {
            v.push_back(i);
        }
        for (auto e: edges) {
            vUnion(e[0], e[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == i) ans++;
        }
        return ans;
    }
};