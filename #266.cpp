#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string s) {
        int num[26];
        memset(num, 0, sizeof(num));
        for (char c: s) {
            num[c-'a']++;
        }
        int val = 0;
        for (int i = 0; i < 26; i++) {
            if (num[i] % 2 != 0) {
                val++;
            }
        }
        if (val == 0) {
            return true;
        }
        if (val == 1 && s.length() % 2 == 1) {
            return true;
        }
        return false;
    }
};