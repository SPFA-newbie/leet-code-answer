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
struct RetPack{
    bool flag;
    int best, maxx, minn, sum;
    RetPack(bool f, int b, int mx, int mn, int s) {
        flag=f;best=b;maxx=mx;minn=mn;sum=s;
    }
};

class Solution {
public:
    RetPack DFS(TreeNode* pos) {
        if(pos->left==nullptr && pos->right==nullptr)
            return RetPack(true, pos->val, pos->val, pos->val, pos->val);

        RetPack ret=RetPack(true, 0, pos->val, pos->val, pos->val);
        int lsum=0, rsum=0;
        if(pos->left!=nullptr) {
            RetPack lp=DFS(pos->left);
            if(lp.best>ret.best) ret.best=lp.best;
            if(lp.flag==false) ret.flag=false;
            if(lp.maxx>=pos->val) ret.flag=false;
            if(lp.maxx>ret.maxx) ret.maxx=lp.maxx;
            if(lp.minn<ret.minn) ret.minn=lp.minn;
            lsum=lp.sum;
        }
        if(pos->right!=nullptr) {
            RetPack rp=DFS(pos->right);
            if(rp.best>ret.best) ret.best=rp.best;
            if(rp.flag==false) ret.flag=false;
            if(rp.minn<=pos->val) ret.flag=false;
            if(rp.maxx>ret.maxx) ret.maxx=rp.maxx;
            if(rp.minn<ret.minn) ret.minn=rp.minn;
            rsum=rp.sum;
        }
        if(ret.flag==true) {
            ret.sum+=(lsum+rsum);
            if(ret.best<ret.sum) ret.best=ret.sum;
        }
        return ret;
    }
    int maxSumBST(TreeNode* root) {
        return DFS(root).best;
    }
};
