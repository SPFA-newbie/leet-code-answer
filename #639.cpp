#include<string>
using namespace std;
const long long MOD=1000000007;

inline int Switch(int n) {return n==1?0:1;}
inline int makeInt(char a, char b) {return (a-'0')*10+(b-'0');}

class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0')
            return 0;
        // 0=不与前项组合 1=与前项组合
        long long ans[2][2];
        long long mem=0;
        int now=1;
        if(s[0]!='*') {
            ans[0][0]=1;
            ans[0][1]=0;
        } else {
            ans[0][0]=9;
            ans[0][1]=0;
            mem=1;
        }

        for(int i=1;i<s.length();i++) {
            if(s[i-1]!='*') {
                if(s[i]=='0') {
                    if(s[i-1]=='0' || makeInt(s[i-1], s[i])>26)
                        return 0;
                    ans[now][0]=0;
                    ans[now][1]=ans[Switch(now)][0];
                } else if(s[i]!='*'){
                    ans[now][0]=ans[Switch(now)][0]+ans[Switch(now)][1];
                    ans[now][0]%=MOD;
                    if(makeInt(s[i-1], s[i])<=26)
                        ans[now][1]=ans[Switch(now)][0];
                    else ans[now][1]=0;
                } else {
                    ans[now][0]=ans[Switch(now)][0]+ans[Switch(now)][1];
                    ans[now][0]%=MOD;
                    mem=ans[now][0];
                    ans[now][0]*=9;
                    ans[now][0]%=MOD;
                    if(s[i-1]=='1') {
                        ans[now][1]=ans[Switch(now)][0]*9;
                        ans[now][1]%=MOD;
                    } else if(s[i-1]=='2') {
                        ans[now][1]=ans[Switch(now)][0]*6;
                        ans[now][1]%=MOD;
                    }else ans[now][1]=0;
                }
            } else {
                if(s[i]=='0') {
                    ans[now][0]=0;
                    ans[now][1]=mem*2;
                    ans[now][1]%=MOD;
                } else if(s[i]!='*'){
                    ans[now][0]=ans[Switch(now)][0]+ans[Switch(now)][1];
                    ans[now][0]%=MOD;
                    if(s[i]<='6')
                        ans[now][1]=mem*2;
                    else ans[now][1]=mem;
                    ans[now][1]%=MOD;
                } else {
                    ans[now][1]=mem*15;
                    ans[now][1]%=MOD;                    
                    ans[now][0]=ans[Switch(now)][0]+ans[Switch(now)][1];
                    ans[now][0]%=MOD;
                    mem=ans[now][0];
                    ans[now][0]*=9;
                    ans[now][0]%=MOD;
                }                
            }
            now=Switch(now);
        }
        now=Switch(now);
        return (ans[now][0]+ans[now][1])%MOD;
    }
};
