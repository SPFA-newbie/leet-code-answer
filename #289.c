inline int Switch(int n) {return n>0?1:0;}

int check(int** m, int r, int c, int x, int y) {
    int num=0;
    r--,c--;
    if(x!=0 && y!=0) num+=Switch(m[x-1][y-1]);
    if(x!=0 && y!=c) num+=Switch(m[x-1][y+1]);
    if(x!=r && y!=0) num+=Switch(m[x+1][y-1]);
    if(x!=r && y!=c) num+=Switch(m[x+1][y+1]);
    if(x!=0) num+=Switch(m[x-1][y]);
    if(x!=r) num+=Switch(m[x+1][y]);
    if(y!=0) num+=Switch(m[x][y-1]);
    if(y!=c) num+=Switch(m[x][y+1]);
    return num;
}

void gameOfLife(int** board, int boardSize, int* boardColSize){
    int rn=boardSize, cn=boardColSize[0];
    for(int i=0;i<rn;i++)
        for(int j=0;j<cn;j++) {
            int res=check(board, rn, cn, i, j);
            if(board[i][j]==1 && res<2) board[i][j]=2; else
            if(board[i][j]==1 && res>3) board[i][j]=2; else
            if(board[i][j]==0 && res==3) board[i][j]=-1;
        }
    
    for(int i=0;i<rn;i++)
        for(int j=0;j<cn;j++)
            if(board[i][j]==2) board[i][j]=0; else
            if(board[i][j]==-1) board[i][j]=1;
    return;
}
