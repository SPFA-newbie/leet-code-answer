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
    int cutTest(int n, int k) {
        int base = n / k;
        int ans = 1;
        for (int i = 0; i < k; i++) {
            if (i < n % k) {
                ans *= base + 1;
            } else {
                ans *= base;
            }
        }
        return ans;
    }
    int integerBreak(int n) {
        int best = 1;
        for (int i = 2; i <= n; i++) {
            int now = cutTest(n, i);
            best = max(best, now);
        }
        return best;
    }
};