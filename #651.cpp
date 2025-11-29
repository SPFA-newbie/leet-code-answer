#include <algorithm>
using namespace std;

class Solution {
public:
    int maxA(int n) {
        int buff[51];
        buff[0] = 0, buff[1] = 1;
        for (int i = 2; i <= n; i++) {
            buff[i] = buff[i-1] + 1;
            for (int j = 2; j < i; j++) {
                buff[i] = max(buff[i], buff[j - 2] * (i - j + 1));
            }
        }
        return buff[n];
    }
};