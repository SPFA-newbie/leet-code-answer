#include<string>
using namespace std;

int calcList[26][100001];

class Solution {
public:
    void makeList() {
        for (int i = 0; i < 25; i++) {
            calcList[i][0] = calcList[i][1] = 1;
        }
        calcList[25][1] = 2;

        for (int i = 2; i <= 100000; i++) {
            for (int j = 0; j < 26; j++) {
                if (j != 25) {
                    calcList[j][i] = calcList[j+1][i-1];
                } else {
                    calcList[j][i] = calcList[0][i - 1] + calcList[1][i - 1];
                    calcList[j][i] %= 1000000007;
                }
            }
        }
    }
    int lengthAfterTransformations(string s, int t) {
        if (calcList[0][1] == 0) {
            makeList();
        }
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            ans += calcList[s[i]-'a'][t];
            ans %= 1000000007;
        }
        return ans;
    }
};