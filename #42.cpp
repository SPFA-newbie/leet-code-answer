#include<vector>
using namespace std; 

inline int getH(int l,int r,int self)
{
	int e=l<r?l:r;
	return self>e?0:e-self;
}

class Solution {
public:
    int trap(vector<int>& height) {
		int left[21000],right[21000];
		left[0]=height[0];
		int size=height.size();
		for(int i=1;i<size;i++)
			left[i]=left[i-1]>height[i]?left[i-1]:height[i];
		right[size-1]=height[size-1];
		for(int i=size-2;i>=0;i--)
			right[i]=right[i+1]>height[i]?right[i+1]:height[i];
		
		int ans=0;
		for(int i=0;i<size;i++)
			ans+=getH(left[i],right[i],height[i]);
		return ans;
    }
};
