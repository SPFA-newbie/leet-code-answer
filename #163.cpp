#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        int start = lower;
        for (auto num: nums) {
            if (num == start) {
                start = num + 1;
            } else {
                vector<int> res = {start, num - 1};
                ans.push_back(res);
                start = num + 1;
            }
        }
        if (start <= upper) {
            vector<int> res = {start, upper};
            ans.push_back(res);
        }
        return ans;
    }
};