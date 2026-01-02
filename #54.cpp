#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<cstring>
#include<string>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct Position {
    int l, r, u, d;
    int x, y;
    int m, n;
    char dir;
    void move() {
        switch(dir) {
            case 'r': {
                x++;
                if (x == n - r) {
                    x--; r++; y++;
                    dir = 'd';
                }
                break;
            }
            case 'd': {
                y++;
                if (y == m - d) {
                    y--; d++; x--;
                    dir = 'l';
                }
                break;
            }
            case 'l': {
                x--;
                if (x == l - 1) {
                    x++; l++; y--;
                    dir = 'u';
                }
                break;
            }
            case 'u': {
                y--;
                if (y == u - 1) {
                    y++; u++; x++;
                    dir = 'r';
                } 
                break;
            }
        }
    }
    Position(int _m, int _n): m(_m), n(_n) {
        x = y = 0;
        u = 1;
        l = r = d = 0;
        dir = 'r';
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        Position pos = Position(matrix.size(), matrix[0].size());
        vector<int> ans;
        for (int i = 0; i < matrix.size() * matrix[0].size(); i++) {
            ans.push_back(matrix[pos.y][pos.x]);
            pos.move();
        }
        return ans;
    }
};