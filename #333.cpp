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
    bool findBST(TreeNode* now, int& best, int& lv, int& rv) {
        if (now == nullptr) {
            return true;
        }
        if (now->left == nullptr && now->right == nullptr) {
            best = 1;
            lv = rv = now->val;
            return true;
        }
        int left = 0, right = 0;
        int llv = now->val, lrv = now->val - 1;
        int rlv = now->val + 1, rrv = now->val;
        bool lres = findBST(now->left, left, llv, lrv);
        bool rres = findBST(now->right, right, rlv, rrv);
        best = max(left, right);
        lv = llv;
        rv = rrv;
        if (now->left != nullptr && now->val <= lrv) {
            return false;
        }
        if (now->right != nullptr && now->val >= rlv) {
            return false;
        }
        if (lres && rres) {
            best = left + right + 1;
            return true;
        }
        best = max(left, right);
        return false;
    }
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        int l, r;
        findBST(root, ans, l, r);
        return ans;
    }
};