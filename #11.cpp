#include<vector>
using namespace std;

inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a<b?b:a;}


class Solution {
public:
    int maxArea(vector<int>& height) {
		vector<int>::iterator p1,p2;
		p1=height.begin();
		p2=height.end();
		p2--;
		
		int ans=0;
		while(p1!=p2)
		{
			int tmp=Min(*p1,*p2)*(p2-p1);
			ans=Max(tmp,ans);
			if(*p1>*p2)p2--;else
				p1++;
		}
		return ans;
    }
};
