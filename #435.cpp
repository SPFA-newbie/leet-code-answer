#include<vector>
#include<algorithm>
using namespace std; 
bool cmp(vector<int> &a, vector<int> &b) {return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans=0;
        int maxr=intervals[0][1];
        for(auto it=intervals.begin()+1;it!=intervals.end();it++) {
            if((*it)[0]<maxr) {
                ans++;
            }else maxr=(*it)[1];
        }
        return ans;
    }
};
