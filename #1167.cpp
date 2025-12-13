#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i: sticks) {
            q.push(i);
        }
        int ans = 0;
        while (!q.empty()) {
            int a = q.top();
            q.pop();
            if (q.empty()) {
                break;
            }
            int b = q.top();
            q.pop();
            ans += (a + b);
            q.push(a + b);
        }
        return ans;
    }
};