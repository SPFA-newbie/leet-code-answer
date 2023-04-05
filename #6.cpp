#include<string>
#include<vector>

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        
        vector<string> vs;
        for(int i=0;i<numRows;i++)
            vs.push_back("");
        
        int dir=1;
        int pos=0;
        for(int i=0;i<s.size();i++) {
            vs[pos].push_back(s[i]);
            pos+=dir;
            if(pos==0 || pos==numRows-1)
                dir=-dir;
        }
        string ans;
        for(int i=0;i<vs.size();i++)
            ans=ans+vs[i];
        return ans;
    }
};
