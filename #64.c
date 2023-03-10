int minPathSum(int** grid, int gridSize, int* gridColSize){
    for(int i=0;i<gridSize;i++)
        for(int j=0;j<gridColSize[i];j++) {
            int up, left;
            if(i!=0)left=grid[i-1][j];
                else left=-1;
            if(j!=0)up=grid[i][j-1];
                else up=-1;
            if(left>=0 && up>=0) grid[i][j]+=(left<up?left:up);else
            if(left>=0) grid[i][j]+=left;else
            if(up>=0) grid[i][j]+=up;
        }
    return grid[gridSize-1][gridColSize[gridSize-1]-1];            
}