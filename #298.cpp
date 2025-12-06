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
    pair<int, int> DFS(TreeNode* pos) {
        int best = 1;
        int lnow = 1, rnow = 1;
        if (pos->left != nullptr) {
            pair<int, int> res = DFS(pos->left);
            if (res.first > best) best = res.first;
            if (pos->left->val - pos->val == 1) lnow = res.second + 1;
        }
        if (pos->right != nullptr) {
            pair<int, int> res = DFS(pos->right);
            if (res.first > best) best = res.first;
            if (pos->right->val - pos->val == 1) rnow = res.second + 1;
        }
        if (lnow > best) best = lnow;
        if (rnow > best) best = rnow;
        return make_pair(best, max(lnow, rnow));
    }
    int longestConsecutive(TreeNode* root) {
        return DFS(root).first;
    }
};