#include<vector>
#include<string>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    set<queue<char>> appear;
    string makeStr(queue<char> q) {
        string ret="";
        while(q.empty()==false) {
             ret.push_back(q.front());
             q.pop();
        }
        return ret;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        queue<char> q;
        set<queue<char>> ans;
        for(int i=0;i<s.length();i++) {
            if(q.size()==10) 
                q.pop();
            q.push(s[i]);
            if(q.size()==10 && appear.find(q)!=appear.end())
                ans.insert(q);
            appear.insert(q);
        }

        vector<string> ret;
        for(auto it=ans.begin();it!=ans.end();it++)
            ret.push_back(makeStr(*it));
        return ret;
    }
};
