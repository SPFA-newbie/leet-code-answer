#include<string>
#include<vector>
#include<set>
using namespace std; 

class Solution {
public:
    set<string> dic;
    vector<string> ans;
    void DFS(string& s, int pos, string now) {
        if(pos==s.length()) {
            ans.push_back(now.substr(0, now.length()-1));
            return;
        }
        for(int i=1;i<=s.length()-pos;i++) {
            string sub=s.substr(pos, i);
            if(dic.find(sub)!=dic.end())
                DFS(s, pos+i, now+sub+" ");
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++)
            dic.insert(wordDict[i]);
        DFS(s, 0, "");
        return ans;
    }
};
