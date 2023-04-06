#include<string>
#include<set>
using namespace std;

class Solution {
public:
    set<string> st;
    void DFS(string& ori, int pos, int now, string nowS) {
        if(now>26)return;
        if(now==0 && ori[pos]=='0')return;
        if(pos==ori.length()) {
            if(now>0)
                nowS.push_back(now-'A'+1);
            st.insert(nowS);
            return;
        }
        
        if(now!=0) {
            string next=nowS;
            next.push_back(now-'A'+1);
            DFS(ori, pos, 0, next);
        }
        now*=10;
        now+=ori[pos]-'0';
        DFS(ori, pos+1, now, nowS);
        return;
    }
    int numDecodings(string s) {
        DFS(s, 0, 0, "");
        return st.size();
    }
};
