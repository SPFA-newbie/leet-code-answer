#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int sub = r - l - 1;
        while (sub > 0) {
            int mid = (r + l) / 2;
            if ((nums[mid] - nums[l]) - (mid - l) < k) {
                k -= (nums[mid] - nums[l]) - (mid - l);
                l = mid;
            } else {
                r = mid;
            }
            sub = r - l - 1;
        }
        if (r == l) {
            return nums[r] + k;
        }
        if (nums[r] - nums[l] - 1 >= k) {
            return nums[l] + k;
        } else {
            k -= nums[r] - nums[l] - 1;
            return nums[r] + k;
        }
    }
};