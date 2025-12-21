#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

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
    deque<int> q;
    bool MidScan(TreeNode* node, double target, int k) {
        if (node == nullptr) {
            return true;
        }
        if (!MidScan(node->left, target, k)) {
            return false;
        }
        q.push_back(node->val);
        if (q.size() > k) {
            if (abs(q.back() - target) < abs(q.front() - target)) {
                q.pop_front();
            } else {
                q.pop_back();
                return false;
            }
        }
        return MidScan(node->right, target, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        q.clear();
        MidScan(root, target, k);
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        return ans;
    }
};