#include<vector>
#include<algorithm>
using namespace std;

inline bool cmp(const vector<int>& a, const vector<int>& b) {
    return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> room;
        sort(intervals.begin(), intervals.end(), cmp);
        room.push_back(-1);
        room.push_back(intervals[0][1]);
        for (int i = 1; i < intervals.size(); i++) {
            int best = 0;
            for (int j = 1; j < room.size(); j++) {
                if (room[j] <= intervals[i][0] && room[j] > room[best]) {
                    best = j;
                }
            }
            if (best == 0) {
                best = room.size();
                room.push_back(0);
            }
            room[best] = intervals[i][1];          
        }
        return room.size() - 1;
    }
};