#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        if (k == 0) {
            int sum = 0;
            for (int b: sweetness) {
                sum += b;
            }    
            return sum;
        }
        int l = 1, r = 1e9 + 1;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            int now = 0;
            int count = 0;
            for (int b: sweetness) {
                now += b;
                if (now >= mid) {
                    count++;
                    now = 0;
                }
            }
            if (count > k) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};