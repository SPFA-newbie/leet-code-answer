#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    void DFS(vector<int>& ans, map<int, vector<int>>& tree, int pid) {
        ans.push_back(pid);
        auto it = tree.find(pid);
        if (it == tree.end()) return;
        for (auto vit = it->second.begin(); vit != it->second.end(); vit++) {
            DFS(ans, tree, *vit);
        }
    }
    
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int>> tree;
        for (int i = 0; i < ppid.size(); i++) {
            if (ppid[i] != 0) {
                if (tree.find(ppid[i]) == tree.end()) {
                    tree.insert(make_pair(ppid[i], vector<int>()));
                }
                tree[ppid[i]].push_back(pid[i]);
            }
        }

        vector<int> ans;
        DFS(ans, tree, kill);
        return ans;
    }
};