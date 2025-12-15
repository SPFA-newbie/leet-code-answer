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
    string raw(string& s) {
        int div = s[0] - 'a';
        string ret = "";
        for (char c: s) {
            if (c - div >= 'a') {
                ret.push_back(c - div);
            } else {
                ret.push_back(c + 26 - div);
            }
        }
        return ret;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> bin;
        for (string& s: strings) {
            string rawStr = raw(s);
            if (bin.find(rawStr) == bin.end()) {
                bin.insert(make_pair(rawStr, vector<string>()));
            }
            bin.find(rawStr)->second.push_back(s);
        }
        vector<vector<string>> ans;
        for (auto& it: bin) {
            ans.push_back(it.second);
        }
        return ans;
    }
};