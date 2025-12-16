#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_set<int> appear;
        unordered_set<int> repeat;
        for (int& n: nums) {
            if (repeat.find(n) == repeat.end()) {
                if (appear.find(n) == repeat.end()) {
                    appear.insert(n);
                } else {
                    appear.erase(n);
                    repeat.insert(n);
                }
            }
        }
        int best = -1;
        for (const int& n: appear) {
            if (n > best) {
                best = n;
            }
        }
        return best;
    }
};