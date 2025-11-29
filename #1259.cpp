long long ans[1001];

class Solution {
public:
    int numberOfWays(int numPeople) {
        ans[0] = ans[2] = 1;
        for (int i = 4; i <= numPeople; i += 2) {
            ans[i] = 0;
            for (int j = 0; j < i; j += 2) {
                ans[i] += (ans[j] * ans[i-j-2]);
                ans[i] %= 1000000007;
            }
        }
        return ans[numPeople] % 1000000007;
    }
};