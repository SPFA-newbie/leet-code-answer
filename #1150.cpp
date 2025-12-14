#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int pos = 0;
        while (pos < nums.size() && nums[pos] != target) pos++;
        return pos + nums.size() / 2 < nums.size() && nums[pos + nums.size() / 2] == target;
    }
};