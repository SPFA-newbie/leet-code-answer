#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return vector<vector<int>>();
        }
        unordered_set<int> numSet;
        for (int n: nums) {
            if (numSet.find(n) == numSet.end()) {
                numSet.insert(n);
            }
        }
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = nums.size() - 1; j > i; j--) {
                if (j != nums.size() - 1 && nums[j] == nums[j+1]) {
                    continue;
                }
                int target = -(nums[i] + nums[j]);
                if (nums[i] == nums[j]) {
                    if (nums[i] == target && i + 1 != j) {
                        vector<int> aAns = {nums[i], nums[i], nums[i]};
                        ans.push_back(aAns);
                    }
                    continue;
                }
                if (target > nums[j] || target < nums[i]) {
                    continue;
                }
                if (target == nums[i]) {
                    if (nums[i+1] == nums[i]) {
                        vector<int> aAns = {nums[i], nums[i], nums[j]};
                        ans.push_back(aAns);
                    }
                    continue;
                }
                if (target == nums[j]) {
                    if (nums[j-1] == nums[j]) {
                        vector<int> aAns = {nums[i], nums[j], nums[j]};
                        ans.push_back(aAns);
                    }
                    continue;
                }
                if (numSet.find(target) != numSet.end()) {
                    vector<int> aAns = {nums[i], target, nums[j]};
                    ans.push_back(aAns);
                }
            }
        }
        return ans;
    }
};