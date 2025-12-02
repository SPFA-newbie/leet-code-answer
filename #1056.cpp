const int cannotRound[5] = {2, 3, 4, 5, 7};

class Solution {
public:
    bool confusingNumber(int n) {
        int oldN = n;
        int newN = 0;
        int now = 0;
        while (n != 0) {
            now = n % 10;
            n /= 10;
            for (int i = 0; i < 5; i++) {
                if (now == cannotRound[i])
                    return false;
            }
            if (now == 6) now = 9;
                else if (now == 9) now = 6;
            newN *= 10;
            newN += now;
        }
        if (newN != oldN) return true;
            else return false;
    }
};