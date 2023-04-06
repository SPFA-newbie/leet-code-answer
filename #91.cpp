#include<string>
using namespace std;

inline int Switch(int n) {return n==1?0:1;}
inline int makeInt(char a, char b) {return (a-'0')*10+(b-'0');}

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        // 0=不与前项组合 1=与前项组合
        int ans[2][2];
        int now=1;
        ans[0][0]=1;
        ans[0][1]=0;
        for(int i=1;i<s.length();i++) {
            if(s[i]=='0') {
                if(s[i-1]=='0' || makeInt(s[i-1], s[i])>26)
                    return 0;
                ans[now][0]=0;
                ans[now][1]=ans[Switch(now)][0];
            } else {
                ans[now][0]=ans[Switch(now)][0]+ans[Switch(now)][1];
                if(makeInt(s[i-1], s[i])<=26)
                    ans[now][1]=ans[Switch(now)][0];
                else ans[now][1]=0;
            }
            now=Switch(now);
        }
        now=Switch(now);
        return ans[now][0]+ans[now][1];
    }
};
