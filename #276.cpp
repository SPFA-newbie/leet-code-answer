int arr[2][100001][2];

class Solution {
public:
    int numWays(int n, int k) {
        arr[0][k][0] = 0;
        for (int i = 0; i < k; i++) {
            arr[0][i][0] = 1;
            arr[0][i][1] = 0;
            arr[0][k][0]++;
        }
        int pos = 0, next = 1;
        for (int i = 1; i < n; i++) {
            arr[next][k][0] = 0;
            for (int j = 0; j < k; j++) {
                arr[next][j][1] = arr[pos][j][0];
                arr[next][j][0] = arr[pos][k][0] - (arr[pos][j][0] + arr[pos][j][1]);
                arr[next][k][0] += (arr[next][j][1] + arr[next][j][0]);
            }
            pos++, next++;
            pos %= 2;
            next %= 2;
        }
        
        return arr[pos][k][0];
    }
};