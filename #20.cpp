#include<string>
using namespace std;
 
class Solution {
public:
    bool isValid(string s) {
		int st[11000];
		int pos=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]=='(')st[pos]=1,pos++;else
			if(s[i]=='[')st[pos]=2,pos++;else
			if(s[i]=='{')st[pos]=3,pos++;else
			if(s[i]==')')
			{
				if(pos!=0 && st[pos-1]==1)pos--;
					else return false;
			}else if(s[i]==']')
			{
				if(pos!=0 && st[pos-1]==2)pos--;
					else return false;
			}else if(s[i]=='}')
			{
				if(pos!=0 && st[pos-1]==3)pos--;
					else return false;
			}
		}
		if(pos==0)return true;
		return false;
    }
};
