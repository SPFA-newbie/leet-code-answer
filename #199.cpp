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
    vector<char> stk;
    void DFS(TreeNode* now, vector<int>& ans, int dep) {
        if(dep==stk.size()) {
            ans.push_back(now->val);
            stk.push_back(0);
        }
        if(now->right!=nullptr)DFS(now->right, ans, dep+1);
        if(now->left!=nullptr)DFS(now->left, ans, dep+1);
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root!=nullptr)
            DFS(root, ans, 0);
        return ans;
    }
};
