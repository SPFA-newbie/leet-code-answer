/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include<map>
using namespace std;

struct STP{
    TreeNode* jp[30];
    int dep;
    STP(int d) {
        dep=d;
        for(int i=0;i<30;i++)
            jp[i]=nullptr;
    }
};
struct cmp {
    bool operator()(const TreeNode* a, const TreeNode* b) const
        {return a->val<b->val;}
};
inline int Min(int a, int b) {return a<b?a:b;}

class Solution {
public:
    map<TreeNode*, STP, cmp> st;
    void stCreate(TreeNode* pos, TreeNode* father, int dep) {
        if(pos==nullptr) return;
        STP now=STP(dep);
        now.jp[0]=father;
        int p=1;
        while(st.find(now.jp[p-1])->second.jp[p-1]!=nullptr) {
            now.jp[p]=st.find(now.jp[p-1])->second.jp[p-1];
            p++;
        }
        st.insert(pair<TreeNode*, STP>(pos, now));
        stCreate(pos->left, pos, dep+1);
        stCreate(pos->right, pos, dep+1);
        return;
    }
    TreeNode* preJMP(TreeNode* pos, int tar) {
        while(st.find(pos)->second.dep!=tar) {
            STP now=st.find(pos)->second;
            int p=29;
            while(now.jp[p]==nullptr || st.find(now.jp[p])->second.dep<tar)
                p--;
            pos=now.jp[p];
        }
        return pos;
    }
    TreeNode* LCA(TreeNode* p, TreeNode* q) {
        while(p!=q) {
            STP pn=st.find(p)->second, qn=st.find(q)->second;
            int js=29;
            while(js>=0 && pn.jp[js]==qn.jp[js])
                js--;
            if(js>=0)
                p=pn.jp[js], q=qn.jp[js];
            p=st.find(p)->second.jp[0], q=st.find(q)->second.jp[0];
        }
        return q;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        st.insert(pair<TreeNode*, STP>(root, STP(0)));
        stCreate(root->left, root, 1);
        stCreate(root->right, root, 1);

        if(st.find(p)->second.dep!=st.find(q)->second.dep) {
            int target=Min(st.find(p)->second.dep, st.find(q)->second.dep);
            p=preJMP(p, target);
            q=preJMP(q, target);
        }

        return LCA(p, q);
    }
};