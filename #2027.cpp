#include<string>
using namespace std; 

class Solution {
public:
    int minimumMoves(string s) {
        int ans=0;
        int i=0;
		for(i=0;i<s.length()-3;i++)
			if(s[i]=='X')
			{
				ans++;
				s[i]=s[i+1]=s[i+2]='O';
			}
		if(s[i]=='X' || s[i+1]=='X' || s[i+2]=='X')
			ans++;
		return ans;
    }
};
