#include<vector>
using namespace std;

class Solution {
public:
    void DFS(vector<vector<int>>& ans, vector<int>& nowList, int n, int last) {
        if (n == 1) {
            if (nowList.size() > 1) {
                vector<int> cpy = nowList;
                ans.push_back(cpy);
            }
            return;
        }
        for (int i = last; i <= n; i++) {
            if (n % i == 0) {
                nowList.push_back(i);
                DFS(ans, nowList, n / i, i);
                nowList.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> getFactors(int n) {
        vector<int> tmp;
        vector<vector<int>> ans;
        DFS(ans, tmp, n, 2);
        return ans;
    }
};