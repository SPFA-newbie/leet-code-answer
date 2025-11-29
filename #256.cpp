#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int arr[2][3];
        int pos = 0, next = 1;
        arr[0][0] = costs[0][0];
        arr[0][1] = costs[0][1];
        arr[0][2] = costs[0][2];
        for (int i = 1; i < costs.size(); i++) {
            arr[next][0] = min(arr[pos][1], arr[pos][2]) + costs[i][0];
            arr[next][1] = min(arr[pos][0], arr[pos][2]) + costs[i][1];
            arr[next][2] = min(arr[pos][0], arr[pos][1]) + costs[i][2];
            pos++, next++;
            pos %= 2;
            next %= 2;
        }
        return min(min(arr[pos][0], arr[pos][1]), arr[pos][2]);
    }
};