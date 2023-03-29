#include<vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > ba;
    int DFS(vector< vector<int> >&map, int x, int y, int m, int n) {
        if(ba[x][y]!=0) return ba[x][y];
        int best=0;
        int tmp;
        if(x+1<m && map[x+1][y]>map[x][y])tmp=DFS(map, x+1, y, m, n);
        best=best>tmp?best:tmp;
        if(x-1>=0 && map[x-1][y]>map[x][y])tmp=DFS(map, x-1, y, m, n);
        best=best>tmp?best:tmp;
        if(y+1<n && map[x][y+1]>map[x][y])tmp=DFS(map, x, y+1, m, n);
        best=best>tmp?best:tmp;
        if(y-1>=0 && map[x][y-1]>map[x][y])tmp=DFS(map, x, y-1, m, n);
        best=best>tmp?best:tmp;
        ba[x][y]=best+1;
        return best+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++) {
            vector<int> now;
            for(int j=0;j<matrix[i].size();j++) {
                now.push_back(0);
            }
            ba.push_back(now);
        }

        int ans=0;
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[i].size();j++) {
                int tmp=DFS(matrix, i, j, matrix.size(), matrix[i].size());
                // ba[i][j]=tmp;
                ans=ans>tmp?ans:tmp;
            }
        return ans;
    }
};