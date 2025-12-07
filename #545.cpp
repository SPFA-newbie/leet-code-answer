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
    void DFS(TreeNode* pos, bool inLeft, bool inRight, vector<int>& ans) {
        if (pos == nullptr) return;
        if (pos->left == nullptr && pos->right == nullptr) {
            ans.push_back(pos->val);
            return;
        }
        if (inLeft) {
            ans.push_back(pos->val);
            DFS(pos->left, true, false, ans);
            if (pos->left == nullptr) {
                DFS(pos->right, true, false, ans);
            } else {
                DFS(pos->right, false, false, ans);
            }
        } else if (inRight) {
            if (pos->right == nullptr) {
                DFS(pos->left, false, true, ans);
            } else {
                DFS(pos->left, false, false, ans);
            }
            DFS(pos->right, false, true, ans);
            ans.push_back(pos->val);
        } else {
            DFS(pos->left, false, false, ans);
            DFS(pos->right, false, false, ans);
        }
        
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        ans.push_back(root->val);
        DFS(root->left, true, false, ans);
        DFS(root->right, false, true, ans);
        return ans;
    }
};