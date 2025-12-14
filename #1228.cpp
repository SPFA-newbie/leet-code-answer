#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& arr) {
        vector<int> sub;
        for (int i = 1; i < arr.size(); i++) {
            sub.push_back(arr[i-1] - arr[i]);
        }
        for (int i = 1; i < sub.size(); i++) {
            if (sub[i] != sub[i-1]) {
                if (abs(sub[i]) > abs(sub[i-1])) {
                    return arr[i] - sub[i-1];
                } else {
                    return arr[i] + sub[i];
                }
            }
        }
        return arr[0];
    }
};