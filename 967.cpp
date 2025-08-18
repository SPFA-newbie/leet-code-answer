#include<vector>
using namespace std;

class Solution {
public:
    void DFS(vector<int> &arr, int last, int pos, int k, int now) {
        if (pos == 0) {
            arr.push_back(now);
            return;
        }
        now *= 10;
        if (last + k < 10) {
            DFS(arr, last + k, pos - 1, k, now + last + k);
        }
        if (k != 0 && last - k >= 0) {
            DFS(arr, last - k, pos - 1, k, now + last - k);
        }
        return;
    } 
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            DFS(ans, i, n - 1, k, i);
        }
        return ans;
    }
};