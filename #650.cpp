inline int Min(int a,int b) {return a<b?a:b;}

class Solution {
public:
    int num[1001][1001];
    int minSteps(int n) {
        num[1][1]=1;
        for(int i=2;i<=n;i++) {
            for(int j=1;j<i;j++) {
                num[i][j]=50*n;
                for(int k=1;i-(k*j)>0;k++)
                    if(num[i-(k*j)][j]!=0)
                        num[i][j]=Min(num[i][j], num[i-(k*j)][j]+k);
            }
            num[i][i]=num[i][1]+1;
            for(int j=2;j<i;j++)
                num[i][i]=Min(num[i][i], num[i][j]+1);
        }
        return num[n][n]-1;
    }
};
