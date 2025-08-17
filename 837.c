#include <string.h>

double probability[21000];

double new21Game(int n, int k, int maxPts)
{
    if (n >= k + maxPts || k == 0) {
        return 1;
    }
    memset(probability, 0, sizeof(probability));
    double perPro = 1.0 / maxPts;
    probability[0] = 1.0;
    int start = 0;
    int end = 0;
    for (int i = 1; i <= k + maxPts; i++) {
        probability[i] = probability[i-1];
        if (start == 0) {
            probability[i] += (probability[end] * perPro);
        } else {
            probability[i] += ((probability[end] - probability[start - 1]) * perPro);
        }
        if (i < k) {
            end = i;
        }
        start = i - maxPts + 1;
        if (start < 0) {
            start = 0;
        }
    }

    return probability[n] - probability[k-1];
}