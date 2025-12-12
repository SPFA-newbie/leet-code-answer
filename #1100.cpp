#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if (k == 1) {
            return s.length();
        }
        unordered_map<char, int> cmap;
        int ans = 0;
        int tail = 0;
        cmap.insert(make_pair(s[0], 0));
        for (int i = 1; i < s.length(); i++) {
            auto it = cmap.find(s[i]);
            if (it == cmap.end()) {
                cmap.insert(make_pair(s[i], i));
                if (i - tail + 1 == k) {
                    ans++;
                    cmap.erase(s[tail]);
                    tail++;
                }
            } else {
                while (tail != it->second) {
                    cmap.erase(s[tail]);
                    tail++;
                }
                it->second = i;
                tail++;
            }
        }
        return ans;
    }
};