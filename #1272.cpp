#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        vector<vector<int>> ans;
        for (auto& nums: intervals) {
            if (nums[1] <= toBeRemoved[0] || nums[0] >= toBeRemoved[1]) {
                ans.push_back(nums);
            } else if (nums[0] < toBeRemoved[0]) {
                if (nums[1] <= toBeRemoved[1]) {
                    ans.push_back(vector<int>({nums[0], toBeRemoved[0]}));
                } else {
                    ans.push_back(vector<int>({nums[0], toBeRemoved[0]}));
                    ans.push_back(vector<int>({toBeRemoved[1], nums[1]}));
                }
            } else if (nums[0] >= toBeRemoved[0]) {
                if (nums[1] > toBeRemoved[1]) {
                    ans.push_back(vector<int>({toBeRemoved[1], nums[1]}));
                }
            }
        }
        return ans;
    }
};