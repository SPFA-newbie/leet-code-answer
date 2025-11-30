#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void DFS(vector<string>& list, string now, int n) {
        if (now.length() == n / 2) {
            if (n % 2 == 1) {
                DFS(list, now + '0', n);
                DFS(list, now + '1', n);
                DFS(list, now + '8', n);
                return;
            }
            for (int i = now.length() - 1; i >= 0; i--) {
                if (now[i] == '6') {
                    now.push_back('9');
                } else if (now[i] == '9') {
                    now.push_back('6');
                } else {
                    now.push_back(now[i]);
                }
            }
            list.push_back(now);
            return;
        } else if (now.length() > n / 2) {
            for (int i = now.length() - 2; i >= 0; i--) {
                if (now[i] == '6') {
                    now.push_back('9');
                } else if (now[i] == '9') {
                    now.push_back('6');
                } else {
                    now.push_back(now[i]);
                }
            }
            list.push_back(now);
            return;
        }
        DFS(list, now + '0', n);
        DFS(list, now + '1', n);
        DFS(list, now + '8', n);
        DFS(list, now + '6', n);
        DFS(list, now + '9', n);
        return;
    }
    vector<string> findStrobogrammatic(int n) {
        vector<string> ans;
        if (n == 1) {
            DFS(ans, "", n);
        } else {
            DFS(ans, "1", n);
            DFS(ans, "8", n);
            DFS(ans, "6", n);
            DFS(ans, "9", n);
        }
        return ans;
    }
};