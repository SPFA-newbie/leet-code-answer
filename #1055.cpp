#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

class Solution {
public:
    int shortestWay(string source, string target) {
        int next[1001][26];
        memset(next, 0, sizeof(next));
        for (int i = source.length() - 2; i >= 0; i--) {
            for (int j = 0; j < 26; j++) {
                next[i+1][j] = next[i+2][j];
            }
            next[i+1][source[i+1]-'a'] = i + 2;
        }
        for (int i = 0; i < 26; i++) {
            next[0][i] = next[1][i];
        }
        next[0][source[0]-'a'] = 1;
        int ans = 1;
        int pos = 0;
        for (auto c: target) {
            pos = next[pos][c-'a'];
            if (pos == 0) {
                ans++;
                if (pos == 0 && next[0][c-'a'] == 0) {
                    return -1;
                }
                pos = next[pos][c-'a'];
            }
        }
        return ans;
    }
};