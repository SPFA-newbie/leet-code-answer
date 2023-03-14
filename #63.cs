public class Solution {
    public int UniquePathsWithObstacles(int[][] obstacleGrid) {
        for(int i=0;i<obstacleGrid.Length;i++)
            for(int j=0;j<obstacleGrid[i].Length;j++)
                if(obstacleGrid[i][j]==1) {
                    obstacleGrid[i][j]=0;
                }else{
                    if(i==0 && j==0)obstacleGrid[i][j]=1;
                    if(i!=0)obstacleGrid[i][j]+=obstacleGrid[i-1][j];
                    if(j!=0)obstacleGrid[i][j]+=obstacleGrid[i][j-1];
                }
        return obstacleGrid[obstacleGrid.Length-1][obstacleGrid[obstacleGrid.Length-1].Length-1];
    }
}