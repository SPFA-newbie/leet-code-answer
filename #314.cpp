/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
inline bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

class Solution {
public:
    void DFS(TreeNode* pos, int col, int dep, map<int, vector<pair<int, int>>>& ans) {
        if (pos == nullptr) return;
        if (ans.find(col) == ans.end()) {
            ans[col] = vector<pair<int, int>>();
        }
        ans[col].push_back(make_pair(pos->val, dep));
        DFS(pos->left, col - 1, dep + 1, ans);
        DFS(pos->right, col + 1, dep + 1, ans);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<pair<int, int>>> ans;
        DFS(root, 0, 0, ans);
        vector<vector<int>> ret;
        for (auto& val: ans) {
            sort(val.second.begin(), val.second.end(), cmp);
            vector<int> col;
            for (auto v: val.second) {
                col.push_back(v.first);
            }
            ret.push_back(col);
        }
        return ret;
    }
};