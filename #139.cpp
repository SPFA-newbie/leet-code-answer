#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    set<string> dic;
    bool m[400][400];
    bool match(string& s, int beg) {
        if(beg==s.length())
            return true;
        for(int i=1;i<=s.length()-beg;i++)
            if(m[beg][i]==true && match(s, beg+i)==true)
                return true;
            else 
                m[beg][i]=false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++)
            dic.insert(wordDict[i]);
        for(int i=0;i<s.length();i++)
            for(int j=1;j<=s.length()-i;j++)
                if(dic.find(s.substr(i, j))!=dic.end())
                    m[i][j]=true;
                else m[i][j]=false;
        
        return match(s, 0);
    }
};
