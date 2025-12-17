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

struct SubNode {
    int val;
    int lv, rv;
    unique_ptr<SubNode> left;
    unique_ptr<SubNode> right;
    SubNode(int _val) :val(_val), lv(0), rv(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    unique_ptr<SubNode> createSubTree(TreeNode* now) {
        if (now == nullptr) {
            return nullptr;
        }
        unique_ptr<SubNode> node = make_unique<SubNode>(now->val);
        node->left = createSubTree(now->left);
        node->right = createSubTree(now->right);
        if (node->left != nullptr) {
            node->lv = node->left->lv;
        } else {
            node->lv = now->val;
        }
        if (node->right != nullptr) {
            node->rv = node->right->rv;
        } else {
            node->rv = now->val;
        }
        return move(node);
    }
    
    bool find(unique_ptr<SubNode>& sub1, unique_ptr<SubNode>& sub2, int target) {
        if (sub1 == nullptr || sub2 == nullptr) {
            return false;
        }
        if (sub1->lv + sub2->lv > target || sub1->rv + sub2->rv < target) {
            return false;
        }
        if (sub1->val + sub2->val == target) {
            return true;
        }
        bool ret = false;
        if (sub1->val + sub2->val > target) {
            if (sub1->val + sub2->lv > target) {
                ret |= find(sub1->left, sub2, target);
            } else if (sub1->lv + sub2->val > target) {
                ret |= find(sub1, sub2->left, target);
            } else {
                ret |= find(sub1->left, sub2, target);
                ret |= find(sub1, sub2->left, target);
            }
        } else {
            if (sub1->val + sub2->rv < target) {
                ret |= find(sub1->right, sub2, target);
            } else if (sub1->rv + sub2->val < target) {
                ret |= find(sub1, sub2->right, target);
            } else {
                ret |= find(sub1->right, sub2, target);
                ret |= find(sub1, sub2->right, target);
            }
        }
        return ret;
    }

    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        unique_ptr<SubNode> sub1 = createSubTree(root1);
        unique_ptr<SubNode> sub2 = createSubTree(root2);
        return find(sub1, sub2, target);
    }
};