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
    int calculateTime(string keyboard, string word) {
        int dis[26][26] = {{0}};
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                dis[keyboard[i]-'a'][keyboard[j]-'a'] = abs(i - j);
            }
        }
        int pos = keyboard[0] - 'a';
        int ans = 0;
        for (char c: word) {
            ans += dis[pos][c-'a'];
            pos = c - 'a';
        }
        return ans;
    }
};