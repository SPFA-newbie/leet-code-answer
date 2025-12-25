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
    int best;
    void DFS(TreeNode* now, int& road) {
        if (now == nullptr) {
            road = -1e8;
            return;
        }
        int lroad, rroad;
        DFS(now->left, lroad);
        DFS(now->right, rroad);
        road = now->val;
        if (lroad + now->val >= road) {
            road = lroad + now->val;
        }
        if (rroad + now->val >= road) {
            road = rroad + now->val;
        }
        best = max(lroad + rroad + now->val, best);
        best = max(lroad + now->val, best);
        best = max(rroad + now->val, best);
        best = max(now->val, best);
        best = max(lroad, best);
        best = max(rroad, best);
    }
    int maxPathSum(TreeNode* root) {
        int road;
        best = root->val;
        DFS(root, road);
        return best;
    }
};