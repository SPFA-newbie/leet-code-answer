#include<vector>
#include<algorithm>
using namespace std;

inline bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};