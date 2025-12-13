#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    map<int, vector<int>> sl;
    void setScore(int id, int score) {
        auto it = sl.find(id);
        if (it == sl.end()) {
            sl.insert(make_pair(id, vector({-1, -1, -1, -1, -1})));
            it = sl.find(id);
        }
        int lowPos = 0;
        for (int i = 1; i < 5; i++) {
            if (it->second[i] < it->second[lowPos]) {
                lowPos = i;
            }
        }
        if (it->second[lowPos] < score) {
            it->second[lowPos] = score;
        }
    }
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        sl.clear();
        for (vector<int>& data: items) {
            setScore(data[0], data[1]);
        }
        vector<vector<int>> ans;
        for (auto it = sl.begin(); it != sl.end(); it++) {
            vector<int> val;
            val.push_back(it->first);
            int avg = 0;
            for (int i = 0; i < 5; i++) {
                avg += it->second[i];
            }
            avg /= 5;
            val.push_back(avg);
            ans.push_back(val);
        }
        return ans;
    }
};