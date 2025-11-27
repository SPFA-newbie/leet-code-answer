#include<string>
using namespace std;

inline int calcByRep(int x) {
    return x * (x + 1) / 2;
}

class Solution {
public:
    int countLetters(string s) {
        int rep = 0;
        int ans = 0;
        char last = 0;
        for (auto c: s) {
            if (c != last) {
                ans += calcByRep(rep);
                rep = 0;
            }
            last = c;
            rep++;
        }
        ans += calcByRep(rep);
        return ans;
    }
};