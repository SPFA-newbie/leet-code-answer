#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int pos = 0;
        for (auto it: shift) {
            if (it[0] == 0) {
                pos += it[1];
                pos %= s.length();
            } else {
                pos -= it[1];
                pos += s.length() * 1000;
                pos %= s.length();
            }
        }
        string ans = s.substr(pos);
        ans += s.substr(0, pos);
        return ans;
    }
};