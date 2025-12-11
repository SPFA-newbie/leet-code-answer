#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:

    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                if (words.size() <= j || words[j].length() <= i) {
                    return false;
                }
                if (words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};