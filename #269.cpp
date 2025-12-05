#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string alienOrder(vector<string>& words) {
        map<char, unordered_set<char>> graph;
        map<char, int> deg;
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (graph.find(words[i][j]) == graph.end()) {
                    graph.insert(make_pair(words[i][j], unordered_set<char>()));
                    deg[words[i][j]] = 0;
                }
            }
        }
        for (int i = 1; i < words.size(); i++) {
            bool accept = false;
            for (int j = 0; j < words[i-1].length() && j < words[i].length(); j++) {
                if (words[i-1][j] != words[i][j]) {
                    auto it = graph.find(words[i-1][j]);
                    int last = it->second.size();
                    it->second.insert(words[i][j]);
                    int now = it->second.size();
                    deg[words[i][j]] += (now - last);
                    accept = true;
                    break;
                }
            }
            if (!accept && words[i-1].length() > words[i].length()) return "";
        }
        int count = 0;
        string ans = "";
        queue<char> q;
        for (auto d: deg) {
            if (d.second == 0) {
                q.push(d.first);
                count++;
            }
        }
        while (!q.empty()) {
            auto edges = graph[q.front()];
            ans.push_back(q.front());
            q.pop();
            for (auto next: edges) {
                deg[next]--;
                if (deg[next] == 0) {
                    q.push(next);
                    count++;
                }
            }
        }
        if (count != graph.size()) return "";
        return ans;
    }
};