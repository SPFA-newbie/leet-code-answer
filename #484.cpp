#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findPermutation(string s) {
        stack<int> down;
        vector<int> ans;
        int num = 2;
        down.push(1);
        for (auto c: s) {
            if (c == 'I') {
                while (!down.empty()) {
                    ans.push_back(down.top());
                    down.pop();
                }
                down.push(num);
            } else {
                down.push(num);
            }
            num++;
        }
        while (!down.empty()) {
            ans.push_back(down.top());
            down.pop();
        }
        return ans;
    }
};