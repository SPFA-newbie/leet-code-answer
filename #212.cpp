#include<vector>
#include<string>
#include<set>
using namespace std;

struct DV {
    char c;
    bool aWord;
    DV* next[26];
    DV(char cc) {
        c=cc;
        aWord=false;
        for(int i=0;i<26;i++)
            next[i]=nullptr;
    }
};

class Solution {
public:
    DV* root;
    set<string> ans;
    bool arr[12][12];
    void makeDict(string& s) {
        DV* pos=root;
        for(int i=0;i<s.length();i++) {
            if(pos->next[s[i]-'a']==nullptr)
                pos->next[s[i]-'a']=new DV(s[i]);
            pos=pos->next[s[i]-'a'];
        }
        pos->aWord=true;
        return;    
    }
    void Clear() {
        for(int i=0;i<12;i++)
            for(int j=0;j<12;j++)
                arr[i][j]=false;
        return;
    }
    void DFS(vector<vector<char>>& m, int xpos, int ypos, DV* dpos, string now) {
        if(arr[xpos][ypos]==true) return;
        if(dpos==nullptr) return;

        if(dpos->c!=0)
            now.push_back(dpos->c);
        if(dpos->aWord==true)
            ans.insert(now);

        arr[xpos][ypos]=true;
        if(xpos-1>=0)
            DFS(m, xpos-1, ypos, dpos->next[m[xpos-1][ypos]-'a'], now);
        if(xpos+1<m.size())
            DFS(m, xpos+1, ypos, dpos->next[m[xpos+1][ypos]-'a'], now);
        if(ypos-1>=0)
            DFS(m, xpos, ypos-1, dpos->next[m[xpos][ypos-1]-'a'], now);
        if(ypos+1<m[0].size())
            DFS(m, xpos, ypos+1, dpos->next[m[xpos][ypos+1]-'a'], now);
        arr[xpos][ypos]=false;
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root=new DV(0);
        for(int i=0;i<words.size();i++)
            makeDict(words[i]);

        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[i].size();j++) {
                Clear();
                DFS(board, i, j, root->next[board[i][j]-'a'], "");
            }

        vector<string> ret;
        ret.assign(ans.begin(), ans.end());
        return ret;
    }
};
