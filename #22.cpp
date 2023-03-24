#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string s="";
        work(0, 0, n, s, ret);
        return ret;
    }
    void work(int use, int now, int maxx, string s, vector<string>& ans) {
        if(use==maxx && now==0) {
            ans.push_back(s);
            return;
        }
        if(now!=0)work(use, now-1, maxx, s+")", ans);
        if(use!=maxx)work(use+1, now+1, maxx, s+"(", ans);
        return;
    }
};