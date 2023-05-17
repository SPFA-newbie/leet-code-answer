int tag=0;
int ans[11000];
inline int Best(int a, int b) {
    if(a==0) return b;
    if(b==0) return a;
    return a<b?a:b;
}

class Solution {
public:
    int numSquares(int n) {
        if(tag!=0) return ans[n];
        tag=1;
        for(int i=0;i<=100;i++) ans[i*i]=1;
        for(int i=1;i<=10000;i++)
            for(int j=1;j<i;j++)
                ans[i]=Best(ans[i], ans[j]+ans[i-j]);
        return ans[n];
    }
};
