class Solution {
public:
    double myPow(double x, int n) {
		if(x==0)return 0;
		if(n==0)return 1;
		long long nn=n;
		if(n<0)
		{
			x=1/x;
			nn=-nn;
		}
		double ans=1;
		while(nn!=0)
		{
			if(nn%2==1)ans*=x;
			x*=x;
			nn/=2;
		}
		return ans;
    }
};
