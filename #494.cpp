#include<vector>
using namespace std;

const int D=1500;
const int AL=3500;

class Solution {
public:
    int t[40][AL];
    int findTargetSumWays(vector<int>& nums, int target) {
        for(int i=0;i<AL;i++)
            for(int j=0;j<40;j++)
                t[j][i]=0;
        int p=1;
        t[1][D+nums[0]]+=1;
        t[1][D-nums[0]]+=1;
        for(auto it=nums.begin();it!=nums.end();it++) {
            int n=*it;
            for(int j=-D;j<D;j++) {
                if(j-n+D>=0 && j-n+D<AL)t[p][j-n+D]+=t[p-1][j+D];
                if(j+n+D>=0 && j+n+D<AL)t[p][j+n+D]+=t[p-1][j+D];
            }
            p++;
        }
        return t[p-1][target+D];
    }
};
