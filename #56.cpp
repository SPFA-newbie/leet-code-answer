#include<algorithm>
#include<vector>
using namespace std;

inline bool cmp(vector<int>& a, vector<int>& b) {return a[0]==b[0]?a[1]>b[1]:a[0]<b[0];}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int start=intervals[0][0], end=intervals[0][1];
        vector<vector<int>> ans;
        for(auto it=intervals.begin();it!=intervals.end();it++) {
            if((*it)[0]>end) {
                vector<int> newAns={start, end};
                ans.push_back(newAns);
                start=(*it)[0];
                end=(*it)[1];
            } else {
                if((*it)[1]>end) end=(*it)[1];
            }
        }
        vector<int> newAns={start, end};
        ans.push_back(newAns);
        return ans;
    }
};
