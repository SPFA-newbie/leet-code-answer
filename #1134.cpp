#include<cmath>
using namespace std;

long qPow(long x, long n) {
    long long ans = 1;
    while (n != 0) {
        if (n % 2) ans *= x;
        x *= x;
        n /= 2;
    }
    return ans;
}

class Solution {
public:
    bool isArmstrong(int n) {
        int x = 0;
        int opn = n;
        int k = 1 + log10(n);
        while (opn != 0) {
            x += qPow(opn % 10, k);
            opn /= 10;
        }
        return x == n;
    }
};