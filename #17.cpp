#include<map>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    map<char, string > mp;
    vector<string> ans;
    void CreateMap() {
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
    }
    void DFS(string& ori, int pos, string now) {
        if(pos==ori.length()) {
            ans.push_back(now);
            return;
        }
        string d=mp[ori[pos]];
        for(int i=0;i<d.length();i++) {
            DFS(ori, pos+1, now+d[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)
            return ans;
        
        CreateMap();
        DFS(digits, 0, "");
        
        return ans;
    }
};
