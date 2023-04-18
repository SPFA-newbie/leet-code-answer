#include<string>
using namespace std;

class Solution {
public:
    string best;
    string find(string& s, int l, int r) {
        while(l>=0 && r<s.length() && s[l]==s[r])
            l--,r++;
        l++,r--;
        return s.substr(l, r-l+1);
    }
    string longestPalindrome(string s) {
        int l=0, r=0;
        while(r!=s.length()) {
            string now=find(s, l, r);
            if(now.length()>best.length())
                best=now;
            if(now.length()==s.length())
                return s;
            if(l==r) r++;
                else l++;
        }
        return best;
    }
};