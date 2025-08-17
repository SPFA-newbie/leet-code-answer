class Solution {
public:
    int maximum69Number (int num) {
        int x = 100000;
        while (x != 0) {
            if (num / x % 10 == 6) {
                return num + (3 * x);
            }
            x /= 10;
        }
        return num;
    }
};