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
#include<vector>
using namespace std;

inline int Abs(int x) {return x<0?-x:x;}

class Solution {
public:
    int best=0;
    vector<int> DFS(TreeNode* pos) {
        if(pos==nullptr) return vector<int>();

        vector<int> v1=DFS(pos->left);
        vector<int> v2=DFS(pos->right);
        v1.insert(v1.end(), v2.begin(), v2.end());
        for(auto it=v1.begin();it!=v1.end();it++)
            if(Abs(*it-pos->val)>best)
                best=Abs(*it-pos->val);
        v1.push_back(pos->val);
        return v1;
    }
    int maxAncestorDiff(TreeNode* root) {
        DFS(root);
        return best;
    }
};