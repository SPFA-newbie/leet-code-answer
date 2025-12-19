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
    void turn(vector<char>& s, int head, int tail) {
        int mid = (head + tail) / 2;
        for (int i = head; i < mid; i++) {
            char c = s[i];
            s[i] = s[tail-(i-head)-1];
            s[tail-(i-head)-1] = c;
        }
    }
    void reverseWords(vector<char>& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            char c = s[i];
            s[i] = s[s.size()-i-1];
            s[s.size()-i-1] = c;
        }
        int head = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                turn(s, head, i);
                head = i + 1;
            }
        }
        if (head != s.size()) {
            turn(s, head, s.size());
        }
    }
};