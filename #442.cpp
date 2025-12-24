#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int base = nums.size() + 1;
        for (int n: nums) {
            nums[n % base - 1] += base;
        }
        for (int i = 0; i < base - 1; i++) {
            if (nums[i] > base * 2) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};