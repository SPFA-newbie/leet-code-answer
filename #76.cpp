#include<string>
#include<cstring>
using namespace std;

inline int arrMap(char c)
{
	if(c>='A' && c<='Z')return c-'A';
	return 26+c-'a';
}

int arr[52];
int resArr[52];

inline bool check()
{
	for(int i=0;i<52;i++)
		if(arr[i]>resArr[i])
			return false;
	return true; 
}

class Solution {
public:
    string minWindow(string s, string t) {
		memset(arr,0,sizeof(arr));
		memset(resArr,0,sizeof(resArr));
		for(int i=0;i<t.length();i++)
			arr[arrMap(t[i])]++;
		
		int p1=0,p2=0,sp1=0,sp2=0;
		while(p1<s.length() && arr[arrMap(s[p1])]==0)p1++;
		
		int min1=0,min2=s.length()+1;
		sp1=p2=sp2=p1;
		while(sp2!=s.length())
		{
			int pos=arrMap(s[sp2]);
			if(arr[pos]!=0)
			{
				p2=sp2;
				resArr[pos]++;
			}
			while(resArr[arrMap(s[p1])]>arr[arrMap(s[p1])])
			{
				resArr[arrMap(s[p1])]--;
				p1++;
				while(p1<p2 && arr[arrMap(s[p1])]==0)p1++;
			}
			if(check()==true && (min2-min1)>=(p2-p1))
			{
				min2=p2;
				min1=p1;
			}
			sp2++;
		}
		if(check()==false)return "";
		return s.substr(min1,min2-min1+1);
    }
};
