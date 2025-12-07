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
    pair<int, int> DFS(TreeNode* pos, double& ans) {
        if (pos == nullptr) return make_pair(0, 0);
        int num = 1;
        int sum = pos->val;
        pair<int, int> ret;
        ret = DFS(pos->left, ans);
        num += ret.first;
        sum += ret.second;
        ret = DFS(pos->right, ans);
        num += ret.first;
        sum += ret.second;
        double val = (double)sum / (double)num;
        if (val > ans) ans = val;
        return make_pair(num, sum);
    }
    double maximumAverageSubtree(TreeNode* root) {
        double ans = 0;
        DFS(root, ans);
        return ans;
    }
};