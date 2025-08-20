#include<vector>
using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        int ans = 0;
        for (auto i = nums.begin(); i != nums.end(); i++) {
            for (auto j = i + 1; j != nums.end(); j++) {
                if (*i != *j) {
                    continue;
                }
                if ((i - nums.begin()) * (j - nums.begin()) % k != 0) {
                    continue;
                }
                ans++;
            }
        }
        return ans;
    }
};