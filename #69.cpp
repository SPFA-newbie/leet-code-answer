#include<cmath>
using namespace std;
double want(double a, double b, int tar)
{
	if(b-a<1e-8)return a;
	double half=(a+b)/2;
	if(half*half==tar)return half;
	if(half*half>tar)return want(a,half,tar);
	return  want(half,b,tar);
} 

class Solution {
public:
    double mySqrt(int x) {
		double r=x;
		r+=1;
		double ret=want(0,r,x);
		if(ceil(ret)-ret<1e-7 && ceil(ret)-ret>1e-15)ret++;
		return floor(ret);
    }
};
