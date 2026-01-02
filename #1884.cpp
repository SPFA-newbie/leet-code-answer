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
    int twoEggDrop(int n) {
        int f[1001] = {0};
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            int best = 10000;
            for (int j = 1; j < i; j++) {
                best = min(best, max(f[i - j], j - 1) + 1);
            }
            f[i] = best;
        }
        return f[n];
    }
};