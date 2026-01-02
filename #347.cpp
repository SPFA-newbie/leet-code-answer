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

inline bool cmp(pair<int, int>& a, pair<int, int>& b) {
    return a.second > b.second;
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> times;
        for (int& n: nums) {
            auto it = times.find(n);
            if (it == times.end()) {
                times.insert(make_pair(n, 1));
            } else {
                it->second++;
            }
        }
        vector<pair<int, int>> res;
        for (auto it = times.begin(); it != times.end(); it++) {
            res.push_back(*it);
        }
        sort(res.begin(), res.end(), cmp);
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(res[i].first);
        }
        return ans;
    }
};