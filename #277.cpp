/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        bool notCel[100];
        memset(notCel, sizeof(notCel), 0);
        int v1 = 0, v2 = 1;
        int count = 0;
        while(1) {
            bool e12 = knows(v1, v2);
            bool e21 = knows(v2, v1);
            if ((e12 && e21) || (!e12 && !e21)) {
                notCel[v1] = true;
                notCel[v2] = true;
                count += 2;
                if (count >= n - 1) break;
                while (v1 == v2 || notCel[v1]) v1++, v1 %= n;
                while (v1 == v2 || notCel[v2]) v2++, v2 %= n;
            } else if (e12) {
                notCel[v1] = true;
                count++;
                if (count >= n - 1) break;
                while (v1 == v2 || notCel[v1]) v1++, v1 %= n;
            } else if (e21) {
                notCel[v2] = true;
                count++;
                if (count >= n - 1) break;
                while (v1 == v2 || notCel[v2]) v2++, v2 %= n;
            }
        }
        if (count >= n) return -1;
        int tar = 0;
        while (notCel[tar]) tar++;
        for (int i = 0; i < n; i++) {
            if (tar == i) {
                continue;
            }
            if (knows(i, tar) && !knows(tar, i)) {
                continue;
            }
            return -1;
        }
        return tar;
    }
};