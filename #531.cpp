#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int ans = 0;
        bool col[500], row[500];
        memset(col, 0, sizeof(col));
        memset(row, 0, sizeof(row));
        for (int i = 0; i < picture.size(); i++) {
            if (row[i] == false) {
                bool acc = false;
                for (int j = 0; j < picture[i].size(); j++) {
                    if (col[j] == false) {
                        if (picture[i][j] == 'B') {
                            acc = true;
                            col[j] = true;
                            if (row[i]) {
                                acc = false;
                            }
                            row[i] = true;
                            for (int k = i + 1; k < picture.size(); k++) {
                                if (picture[k][j] == 'B') {
                                    row[k] = true;
                                    acc = false;
                                }
                            }
                        }
                    }
                }
                if (acc) {
                    ans++;
                }
            }
        }
        return ans;
    }
};