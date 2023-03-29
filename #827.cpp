#include<vector>
using namespace std;

class Solution {
public:
    vector<int> islands;
    int DFS(vector< vector<int> >& m, int x, int y, int id) {
        int sum=1;
        m[x][y]=id;
        if(x-1>=0 && m[x-1][y]==1)sum+=DFS(m, x-1, y, id);
        if(y-1>=0 && m[x][y-1]==1)sum+=DFS(m, x, y-1, id);
        if(x+1<m.size() && m[x+1][y]==1)sum+=DFS(m, x+1, y, id);
        if(y+1<m[x].size() && m[x][y+1]==1)sum+=DFS(m, x, y+1, id);
        return sum;
    }
    inline int getSize(vector<vector<int>>& m, int x, int y) {
        if(x<0 || x>=m.size() || y<0 || y>=m[x].size())
            return 0;
        return islands[m[x][y]];
    }
    inline bool cmpId(vector<vector<int>>& m, int x1, int y1, int x2, int y2) {
        if(x1<0 || x1>=m.size() || y1<0 || y1>=m[x1].size())return false;
        if(x2<0 || x2>=m.size() || y2<0 || y2>=m[x2].size())return false;
        if(m[x1][y1]==0 || m[x2][y2]==0)return false;
        return m[x1][y1]==m[x2][y2];
    }
    int check(vector<vector<int>>& m, int x, int y) {
        int val=1+getSize(m, x-1, y);
        if(cmpId(m, x-1, y, x+1, y)==false)val+=getSize(m, x+1, y);
        if(cmpId(m, x-1, y, x, y-1)==false && cmpId(m, x+1, y, x, y-1)==false)
            val+=getSize(m, x, y-1);
        if(cmpId(m, x-1, y, x, y+1)==false && cmpId(m, x+1, y, x, y+1)==false && 
           cmpId(m, x, y-1, x, y+1)==false)
           val+=getSize(m, x, y+1);
        return val;
    }
    int largestIsland(vector<vector<int>>& grid) {
        islands.push_back(0);
        islands.push_back(0);
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==1)
                    islands.push_back(DFS(grid, i, j, islands.size()));
        
        int best=0;
        for(int i=0;i<islands.size();i++)
            best=best>islands[i]?best:islands[i];
        
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[i].size();j++)
                if(grid[i][j]==0) {
                    int val=check(grid, i, j);
                    best=val>best?val:best;
                }
        return best;          
    }
};
