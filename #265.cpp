#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int arr[2][22];
        int best[2][2];
        int k = costs[0].size();
        int pos = 0, next = 1;
        arr[0][k] = arr[0][k+1] = 100;
        for (int i = 0; i < k; i++) {
            arr[0][i] = costs[0][i];
            if (arr[0][i] < arr[0][k]) {
                arr[0][k+1] = arr[0][k];
                best[0][1] = best[0][0];
                arr[0][k] = arr[0][i];
                best[0][0] = i;
            } else if (arr[0][i] < arr[0][k+1]) {
                arr[0][k+1] = arr[0][i];
                best[0][1] = i;
            }
        }
        for (int i = 1; i < costs.size(); i++) {
            arr[next][k] = arr[next][k+1] = 1000000;
            for (int j = 0; j < k; j++) {
                if (j != best[pos][0]) {
                    arr[next][j] = arr[pos][k] + costs[i][j];
                } else {
                    arr[next][j] = arr[pos][k+1] + costs[i][j];
                }
                if (arr[next][j] < arr[next][k]) {
                    arr[next][k+1] = arr[next][k];
                    best[next][1] = best[next][0];
                    arr[next][k] = arr[next][j];
                    best[next][0] = j;
                } else if (arr[next][j] < arr[next][k+1]){
                    arr[next][k+1] = arr[next][j];
                    best[next][1] = j;
                }
            }
            pos++, next++;
            pos %= 2;
            next %= 2;
        }
        return arr[pos][k];
    }
};