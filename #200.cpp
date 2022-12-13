#include<vector>
#include<cstring>
using namespace std;
 
bool arr[301][301];
int maxX,maxY;
void DFS(int x,int y,vector<vector<char>>& grid)
{
	if(arr[x][y])return;
	if(grid[x][y]==0 || grid[x][y]=='0')return;
	arr[x][y]=true;
	if(x!=0)DFS(x-1,y,grid);
	if(y!=0)DFS(x,y-1,grid);
	if(x!=maxX-1)DFS(x+1,y,grid);
	if(y!=maxY-1)DFS(x,y+1,grid);
	return;
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        memset(arr,0,sizeof(arr));
        maxX=grid.size();
        maxY=grid[0].size();
        
        int ans=0;
        for(int i=0;i<maxX;i++)
        	for(int j=0;j<maxY;j++)
        		if((grid[i][j]==1 || grid[i][j]=='1')&&arr[i][j]==false)
        		{
        			ans++;
        			DFS(i,j,grid);
				}
		return ans;
    }
};
