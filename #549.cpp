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
struct Data{
    int up, down;
    Data(int u, int d) {
        up = u;
        down = d;
    }
};

class Solution {
public:
    pair<int, Data> DFS(TreeNode* pos) {
        int best = 1;
        Data lnow = Data(1, 1), rnow = Data(1, 1);
        if (pos->left != nullptr) {
            pair<int, Data> res = DFS(pos->left);
            if (res.first > best) best = res.first;
            if (pos->left->val - pos->val == 1) lnow.up = res.second.up + 1;
            if (pos->val - pos->left->val == 1) lnow.down = res.second.down + 1;
        }
        if (pos->right != nullptr) {
            pair<int, Data> res = DFS(pos->right);
            if (res.first > best) best = res.first;
            if (pos->right->val - pos->val == 1) rnow.up = res.second.up + 1;
            if (pos->val - pos->right->val == 1) rnow.down = res.second.down + 1;
        }
        if (lnow.up > best) best = lnow.up;
        if (lnow.down > best) best = lnow.down;
        if (rnow.up > best) best = rnow.up;
        if (rnow.down > best) best = rnow.down;
        if (lnow.up + rnow.down - 1 > best) best = lnow.up + rnow.down - 1;
        if (rnow.up + lnow.down - 1 > best) best = rnow.up + lnow.down - 1;
        return make_pair(best, Data(max(lnow.up, rnow.up), max(lnow.down, rnow.down)));
    }
    int longestConsecutive(TreeNode* root) {
        return DFS(root).first;
    }
};