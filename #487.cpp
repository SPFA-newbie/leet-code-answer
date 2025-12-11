#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

class Solution {
public:
    int calc(int s1, int s2, int e1, int e2, int size) {
        if (e1 + 2 == s2) {
            return e2 - s1 + 1;
        }
        if (e2 != size - 1 || s2 != 0) {
            return e2 - s2 + 2;
        }
        return e2 - s2 + 1;
    }
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start1 = 0, start2 = 0;
        int end1 = 0, end2 = 0;
        int best = 1;
        int i = 0;
        while (i < nums.size() && nums[i] == 0) {
            i++;
        }
        start1 = start2 = end1 = end2 = i;
        for (; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (i != 0 && nums[i-1] == 0) {
                    start1 = start2;
                    end1 = end2;
                    start2 = i;
                }
                end2 = i;
                best = max(best, calc(start1, start2, end1, end2, nums.size())); 
            }
        }
        return best;
    }
};