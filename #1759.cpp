#include<string>
using namespace std;

const int MOD=1000000007;

inline int cal(int n)
{
	long long ori=n;
	ori=ori*(ori+1);
	ori/=2;
	return ori%MOD;
} 

class Solution {
public:
    int countHomogenous(string s) {
		int ans=0;
		int cnt=0;
		char now=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]==now)cnt++;
			else{
				ans+=cal(cnt);
				ans%=MOD;
				cnt=1;
				now=s[i];
			}
		}
		ans+=cal(cnt);
		ans%=MOD;
		return ans;
    }
};
