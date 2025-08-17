/* O(k*N)会超时 */
#include <string.h>

double probability[21000];

double new21Game(int n, int k, int maxPts)
{
    memset(probability, 0, sizeof(probability));
    double perPro = 1.0/maxPts;
    probability[0] = 1.0;
    for (int i = 1; i < k + maxPts; i++) {
        for (int j = (i - maxPts < 0 ? 0 : i - maxPts); j < i && j < k; j++) {
            probability[i] += (probability[j] * perPro);
        }
    }
    double ans = 0.0;
    for (int i = k; i <= n; i++) {
        ans += probability[i];
    }
    return ans;
}