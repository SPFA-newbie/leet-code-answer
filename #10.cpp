#include<string>
#include<vector>
using namespace std;

struct MItem {
    char c;
    bool rep;
    MItem(char cc, bool rr) {
        c=cc,rep=rr;
    }
};

class Solution {
public:
    vector<MItem> mp;
    bool match(string& s, int sp, int pp) {
        if(pp==mp.size() && sp==s.length()) return true;
        if(pp==mp.size()) return false;
        if(mp[pp].rep==false && sp==s.length()) return false;
        
        if(mp[pp].rep==false) {
            if(mp[pp].c=='.' || mp[pp].c==s[sp]) 
                return match(s, sp+1, pp+1);
            return false;
        } else {
            bool res=match(s, sp, pp+1);
            int tp=sp;
            char mc=mp[pp].c;
            while(tp!=s.length() && (mc=='.' || s[tp]==mc)) {
                tp++;
                res|=match(s, tp, pp+1);
            }
            return res;
        }
    }    
    bool isMatch(string s, string p) {
        for(int i=0;i<p.length();i++) {
            if(i!=p.length()-1 && p[i+1]=='*') {
                mp.push_back(MItem(p[i], true));
                i++;
            }else mp.push_back(MItem(p[i], false));
        }
        return match(s, 0, 0);
    }
};
