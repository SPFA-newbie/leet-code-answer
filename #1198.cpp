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
    int smallestCommonElement(vector<vector<int>>& mat) {
        int tail = 0;
        int rowPos[500] = {0};
        int pos = 0;
        int ans = 0;
        do {
            while (rowPos[pos] < mat[pos].size() && mat[pos][rowPos[pos]] < ans) {
                rowPos[pos]++;
            }
            if (rowPos[pos] == mat[pos].size()) {
                return -1;
            }
            if (mat[pos][rowPos[pos]] != ans) {
                ans = mat[pos][rowPos[pos]];
                tail = pos;
            }
            pos++;
            pos %= mat.size();
        } while (pos != tail);
        return ans;
    }
};