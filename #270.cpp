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
    int closestValue(TreeNode* root, double target) {
        int best = root->val;
        double bestSub = abs(target - root->val);
        int child;
        if (root->left != nullptr) {
            child = closestValue(root->left, target);
            if (abs(target - child) <= bestSub) {
                bestSub = abs(target - child);
                best = child;
            }
        }
        if (root->right != nullptr) {
            child = closestValue(root->right, target);
            if (abs(target - child) < bestSub) {
                bestSub = abs(target - child);
                best = child;
            }
        }     
        return best;
    }
};