#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        bool zero1[100], zero2[100];
        memset(zero1, 0, sizeof(zero1));
        memset(zero2, 0, sizeof(zero2));
        for (int i = 0; i < mat1.size(); i++) {
            zero1[i] = true;
            for (int j = 0; j < mat1[i].size(); j++) {
                if (mat1[i][j] != 0) {
                    zero1[i] = false;
                    break;
                }
            }
        }
        for (int i = 0; i < mat2[0].size(); i++) {
            zero2[i] = true;
            for (int j = 0; j < mat2.size(); j++) {
                if (mat2[j][i] != 0) {
                    zero2[i] = false;
                    break;
                }
            }
        }
        vector<int> zeroRow;
        for (int i = 0; i < mat1[0].size(); i++) {
            zeroRow.push_back(0);
        }
        vector<vector<int>> ans;
        for (int i = 0; i < mat1.size(); i++) {
            if (zero1[i]) {
                ans.push_back(zeroRow);
            } else {
                vector<int> row;
                for (int j = 0; j < mat2[0].size(); j++) {
                    if (zero2[j]) {
                        row.push_back(0);
                        continue;
                    }
                    int p = 0;
                    for (int k = 0; k < mat2.size(); k++) {
                        p += (mat1[i][k] * mat2[k][j]);
                    }
                    row.push_back(p);
                }
                ans.push_back(row);
            }
        }
        return ans;
    }
};