#include<string>

class Solution {
public:
    string greatestLetter(string s) {
        bool upper[26];
        bool lower[26];
        for(int i=0;i<26;i++)
			upper[i]=lower[i]=false;
        for(int i=0;i<s.length();i++)
        	if(s[i]>='a' && s[i]<='z')
        		lower[s[i]-'a']=true;
        	else upper[s[i]-'A']=true;
        for(int i=25;i>=0;i--)
        	if(upper[i] && lower[i])
        		return string(1, i+'A');
        return "";
    }
};
