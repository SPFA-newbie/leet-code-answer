#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void make(vector<int>& nums, int pos, vector<int>& tar, set< vector<int> >& ans) {
        if(pos==nums.size())return;
        make(nums, pos+1, tar, ans);
        tar.push_back(nums[pos]);
        make(nums, pos+1, tar, ans);
        vector<int> now;
        now.assign(tar.begin(), tar.end());
        sort(now.begin(), now.end());
        ans.insert(now);
        tar.pop_back();
        return;
    }
    vector< vector<int> > subsetsWithDup(vector<int>& nums) {
        set< vector<int> > ans;
        vector<int> bas;
        make(nums, 0, bas, ans);
        ans.insert(bas);
        vector< vector<int> > ret;
        ret.assign(ans.begin(), ans.end());
        return ret;
    }
};
