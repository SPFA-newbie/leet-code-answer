class Solution {
public:
    bool use[10][10];
    int n;
    bool check(int x, int y) {
        for(int i=0;i<10;i++)
        {
            if(i!=x && use[i][y])return false;
            if(i!=y && use[x][i])return false;
        }
        int sx=x,sy=y;
        while(sx!=0 && sy!=0)sx--,sy--;
        while(sx<10 && sy<10)
        {
            if(sx!=x && sy!=y && use[sx][sy])
                return false;
            sx++,sy++;
        }
        sx=x,sy=y;
        while(sx!=0 && sy!=9)sx--,sy++;
        while(sx<10 && sy>=0)
        {
            if(sx!=x && sy!=y && use[sx][sy])
                return false;
            sx++,sy--;
        }
        return true;
    }
    int DFS(int row) {
        if(row>n)return 1;
        int ans=0;
        for(int i=1;i<=n;i++) {
            if(check(row, i)==true) {
                use[row][i]=true;
                ans+=DFS(row+1);
                use[row][i]=false;
            }
        }
        return ans;
    }
    int totalNQueens(int n) {
        this->n=n;
        return DFS(1);
    }
};
