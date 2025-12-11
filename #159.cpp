#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int best = 0;
        int aEnd = 0, bEnd = -1;
        char a = s[0], b = 0;
        int start = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                if (s[i-1] == a) {
                    aEnd = i;
                } else {
                    bEnd = i;
                }
            } else {
                if (s[i-1] == a && s[i] != b) {
                    best = max(best, i - start);
                    start = bEnd + 1;
                    b = s[i];
                    bEnd = i;
                } else if (s[i-1] == b && s[i] != a) {
                    best = max(best, i - start);
                    start = aEnd + 1;
                    a = s[i];
                    aEnd = i;
                } else if (s[i] == a) {
                    aEnd = i;
                } else {
                    bEnd = i;
                }
            }
        }
        best = max(best, (int)s.length() - start);
        return best;
    }
};