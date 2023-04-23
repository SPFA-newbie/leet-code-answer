class Solution {
public:
    int p[60][60][60];
    const int MOD=1e9+7;
    int SUM(int i, int j, int k, int m, int n) {
        int ret=0;
        if(j!=0) ret+=p[i-1][j-1][k];
        if(j!=m-1) ret+=p[i-1][j+1][k];
        ret%=MOD;
        if(k!=0) ret+=p[i-1][j][k-1];
        ret%=MOD;
        if(k!=n-1) ret+=p[i-1][j][k+1];
        ret%=MOD;
        return ret;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        p[0][startRow][startColumn]=1;
        for(int i=1;i<maxMove;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<n;k++)
                    p[i][j][k]=SUM(i, j, k, m, n);
        
        int ans=0;
        for(int i=0;i<maxMove;i++) {
            for(int j=0;j<m;j++) {
                ans+=p[i][j][0];
                ans%=MOD;
                ans+=p[i][j][n-1];
                ans%=MOD;
            }
            for(int j=0;j<n;j++) {
                ans+=p[i][0][j];
                ans%=MOD;
                ans+=p[i][m-1][j];
                ans%=MOD;
            }
        }
        return ans;
    }
};