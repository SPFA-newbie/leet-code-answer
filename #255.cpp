#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    void tryBuild(vector<int>& nums, int& pos, int left, int right) {
        if (pos == nums.size()) {
            return;
        }
        if (nums[pos] < left || nums[pos] > right) {
            return;
        }
        int now = pos;
        pos++;
        tryBuild(nums, pos, left, nums[now]);
        tryBuild(nums, pos, nums[now], right);
    }
    bool verifyPreorder(vector<int>& preorder) {
        int pos = 0;
        tryBuild(preorder, pos, 0, 1e5);
        return pos == preorder.size();
    }
};