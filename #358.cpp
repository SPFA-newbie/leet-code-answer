#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct cmp {
    bool operator()(pair<char, int>& a, pair<char, int>& b) const {
        return a.second < b.second;
    }
};

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 1) {
            return s;
        }
        int cnums[26] = {0};
        priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
        queue<pair<char, int>> q;
        for (char& c: s) {
            cnums[c-'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (cnums[i] != 0) {
                pq.push(make_pair(static_cast<char>(i + 'a'), cnums[i]));
            }
        }
        string ans = "";
        while (!pq.empty()) {
            pair<char, int> now = pq.top();
            pq.pop();
            ans.push_back(now.first);
            now.second--;
            q.push(now);
            if (q.size() >= k) {
                if (q.front().second != 0) {
                    pq.push(q.front());
                }
                q.pop();
            }
        }
        while (!q.empty()) {
            if (q.front().second != 0) {
                return "";
            }
            q.pop();
        }
        return ans;
    }
};