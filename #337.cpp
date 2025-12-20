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
typedef long long p_size;

class Solution {
public:
    unordered_map<p_size, pair<int, int>> dy;
    int getRob(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return dy.find(reinterpret_cast<p_size>(node))->second.first;
    }
    int getNotRob(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return dy.find(reinterpret_cast<p_size>(node))->second.second;
    }
    void calcVal(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        calcVal(node->left);
        calcVal(node->right);
        int r = getNotRob(node->left) + getNotRob(node->right) + node->val;
        int nr = max(getNotRob(node->left), getRob(node->left)) + max(getNotRob(node->right), getRob(node->right));
        dy.insert(make_pair(reinterpret_cast<p_size>(node), make_pair(r, nr)));

    }
    int rob(TreeNode* root) {
        dy.clear();
        calcVal(root);
        return max(getRob(root), getNotRob(root));
    }
};