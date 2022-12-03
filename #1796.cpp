#include<string>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
		int maxx=-1;
		int ans=-1;
		for(int i=0;i<s.length();i++)
			if(s[i]-'0'>=0 && s[i]-'0'<=9)
			{
				if(s[i]-'0'>maxx)
				{
					ans=maxx;
					maxx=s[i]-'0';
				}else if(s[i]-'0'!=maxx && s[i]-'0'>ans)
				{
					ans=s[i]-'0';
				}
			}
		return ans;
    }
};
