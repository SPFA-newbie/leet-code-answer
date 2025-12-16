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
    int countElements(vector<int>& arr) {
        int val[1002] = {0};
        int maxN = 0;
        for (int& n: arr) {
            val[n]++;
            maxN = n > maxN ? n : maxN;
        }
        int ans = 0;
        for (int i = 0; i <= maxN; i++) {
            if (val[i+1] != 0) {
                ans += val[i];
            }
        }
        return ans;
    }
};