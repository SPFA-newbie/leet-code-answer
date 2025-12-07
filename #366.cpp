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
class Solution {
public:
    int DFS(TreeNode* pos, vector<vector<int>>& ans) {
        if (pos == nullptr) return 0;
        int removeTime = 1;
        int childTime;
        childTime = DFS(pos->left, ans);
        if (childTime + 1 > removeTime) removeTime = childTime + 1;
        childTime = DFS(pos->right, ans);
        if (childTime + 1 > removeTime) removeTime = childTime + 1;
        while (ans.size() < removeTime) {
            ans.push_back(vector<int>());
        }
        ans[removeTime-1].push_back(pos->val);
        return removeTime;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        DFS(root, ans);
        return ans;
    }
};