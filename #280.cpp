#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(), j = next(nums.begin()); i != nums.end() && j != nums.end();) {
            if (next(i) != nums.end()) i = next(i, 2);
                else break;
            if (i == nums.end()) break;
            int x = *j;
            *j = *i;
            *i = x;
            if (next(j) != nums.end()) j = next(j, 2);
        }
    }
};