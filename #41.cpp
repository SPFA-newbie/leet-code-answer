#include<vector> 
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]>0 && nums[i]<=nums.size())
			{
				if(nums[i]!=i+1)
				{
					if(nums[nums[i]-1]!=nums[i])
					{
						int tmp=nums[nums[i]-1];
						nums[nums[i]-1]=nums[i];
						nums[i]=tmp;
						i--;
					}else nums[i]=0;
				}
			}else nums[i]=0;
		}
		for(int i=0;i<nums.size();i++)
			if(nums[i]==0)
				return i+1;
		return nums.size()+1;
    }
};
