#include<string>
using namespace std;

inline int ABS(int x) {return x > 0 ? x : -x;}

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (ABS(s.length() - t.length()) > 1) return false;
        if (s.length() == 0 && t.length() == 0) return false;
        if (s.length() == 0 || t.length() == 0) return true;
        bool diff = false;
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (diff == false) {
                if (s[i] == t[j]) {
                    i++, j++;
                    continue;
                }
                diff = true;
                if (s.length() >= t.length()) i++;
                if (s.length() <= t.length()) j++;
                continue;
            }
            if (s[i] != t[j]) return false;
            i++, j++;
        }
        if (diff == false && s.length() != t.length())
            return true;
        return diff;
    }
};