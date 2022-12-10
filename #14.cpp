#include<string>
#include<vector>
using namespace std;

inline int Max(int a,int b){return a>b?a:b;}

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		int maxx=0;
		for(int i=0;i<strs.size();i++)
			maxx=Max(maxx,strs[i].size());
		
		string ret="";
		char now;
		for(int i=0;i<maxx;i++)
		{
			if(strs[0].size()<=i)return ret;
			now=strs[0][i];
			for(int j=1;j<strs.size();j++)
				if(strs[j].size()<=i || strs[j][i]!=now)
					return ret;
			ret.push_back(now);
		}
		return ret;
    }
};
