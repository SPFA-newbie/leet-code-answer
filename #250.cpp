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
    bool DFS(TreeNode* pos, int& ans) {
        bool ret = true;
        if (pos->left != nullptr) {
            if (!(DFS(pos->left, ans) && pos->val == pos->left->val)) {
                ret = false;
            }
        }
        if (pos->right != nullptr) {
            if (!(DFS(pos->right, ans) && pos->val == pos->right->val)) {
                ret = false;
            }
        }
        if (ret) ans++;
        return ret;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        if (root == nullptr) return 0;
        DFS(root, ans);
        return ans;
    }
};