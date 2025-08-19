#include<vector>
using namespace std;

class Solution {
public:
    long long calc(int val) {
        long long res = val;
        return res * (res + 1) / 2;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int len = 0;
        for (auto it = nums.begin(); it != nums.end(); it++) {
            if (*it != 0) {
                ans += calc(len);
                len = 0;
            } else {
                len++;
            }
        }
        ans += calc(len);
        return ans;
    }
};