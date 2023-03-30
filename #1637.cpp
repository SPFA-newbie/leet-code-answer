#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a[0]<b[0];
}

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int best=0;
        for(int i=1;i<points.size();i++)
            if(points[i][0]-points[i-1][0]>best)
                best=points[i][0]-points[i-1][0];
        return best;
    }
};