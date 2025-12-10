#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

inline bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first == b.first ? a.second < b.second : a.first < b.first;
}

class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        vector<pair<int, int>> bList;
        bList.push_back(make_pair(-100, -100));
        for (string& word: words) {
            for (int i = 0; i < s.length() - word.length() + 1; i++) {
                int start = s.find(word, i);
                if (start == string::npos) {
                    break;
                }
                bList.push_back(make_pair(start, start + word.length() - 1));
            }
        }
        sort(bList.begin(), bList.end(), cmp);
        vector<pair<int, int>> trueList;
        trueList.push_back(bList[0]);
        for (int i = 1; i < bList.size(); i++) {
            if (bList[i].first <= trueList[trueList.size()-1].second + 1) {
                trueList[trueList.size()-1].second = max(trueList[trueList.size()-1].second, bList[i].second);
            } else {
                trueList.push_back(bList[i]);
            }
        }
        string ans;
        int pos = 1;
        for (int i = 0; i < s.length(); i++) {
            if (pos < trueList.size() && i == trueList[pos].first) {
                ans += "<b>";
            }
            ans.push_back(s[i]);
            if (pos < trueList.size() && i == trueList[pos].second) {
                ans += "</b>";
                pos++;
            }
        }
        return ans;
    }
};