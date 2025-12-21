#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> q;
        q.push_back(num[0]);
        for (int i = 1; i < num.length(); i++) {
            while (!q.empty() && num[i] < q.back() && k != 0) {
                q.pop_back();
                k--;
            }
            q.push_back(num[i]);
        }
        while (k != 0 && !q.empty()) {
            q.pop_back();
            k--;
        }
        string ans;
        while (!q.empty() && q.front() == '0') {
            q.pop_front();
        }
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop_front();
        }
        if (ans.length() == 0) {
            ans.push_back('0');
        }
        return ans;
    }
};