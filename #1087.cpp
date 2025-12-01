#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    void DFS(vector<string>& ans, string now, string& s, int pos) {
        if (pos >= s.length()) {
            ans.push_back(now);
            return;
        }
        while (pos < s.length() && s[pos] != '{') {
            now.push_back(s[pos]);
            pos++;
        }
        if (pos == s.length()) {
            ans.push_back(now);
            return;
        }
        pos++;
        priority_queue< char, vector<char>, greater<char> > priority;
        while (pos < s.length() && s[pos] != '}') {
            if (s[pos] != ',') priority.push(s[pos]);
            pos++;
        }
        while (priority.empty() != true) {
            DFS(ans, now + priority.top(), s, pos + 1);
            priority.pop();
        }
        return;
    }
    vector<string> expand(string s) {
        vector<string> ans;
        string tmp;
        DFS(ans, "", s, 0);
        return ans;
    }
};