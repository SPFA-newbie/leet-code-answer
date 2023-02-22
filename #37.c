void solveSudoku(char** board, int boardSize, int* boardColSize){
    make(board, 0, 0, 9);
    return;
}

int make(char** b, int x, int y, int bs){
    if(x==bs)return 1;
    if(b[x][y]!='.')
        return make(b, y+1==bs?x+1:x, y+1==bs?0:y+1, bs);
    for(int i=1;i<=9;i++){
        b[x][y]=i+'0';
        if(check(b, x, y, bs)==1){
            int res=make(b, y+1==bs?x+1:x, y+1==bs?0:y+1, bs);
            if(res==1)return 1;
        }
    }
    b[x][y]='.';
    return -1;
}

int check(char** b, int x, int y, int bs){
    for(int i=0;i<bs;i++){
        if(i!=y && b[x][i]==b[x][y])
            return -1;
        if(i!=x && b[i][y]==b[x][y])
            return -1;
    }
    int xx=x/3,yy=y/3;
    for(int i=xx*3;i<(xx+1)*3;i++)
        for(int j=yy*3;j<(yy+1)*3;j++)
            if(i!=x && j!=y && b[i][j]==b[x][y])
                return -1;
    return 1;
}