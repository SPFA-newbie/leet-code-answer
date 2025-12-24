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
    int minSubArrayLen(int target, vector<int>& nums) {
        queue<int> q;
        int best = nums.size() + 1;
        int sum = 0;
        for (int n: nums) {
            sum += n;
            q.push(n);
            if (sum >= target) {
                best = min(static_cast<int>(q.size()), best);
            }
            while (sum >= target) {
                sum -= q.front();
                best = min(static_cast<int>(q.size()), best);
                q.pop();
            }
        }
        if (best == nums.size() + 1) {
            return 0;
        }
        return best;
    }
};