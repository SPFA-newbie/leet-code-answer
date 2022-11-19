#include<set>
#include<vector>
using namespace std;

class Solution {
public:
   	vector<int> twoSum(vector<int>& nums, int target) 
	{	
		vector<int> ret;
		set<int> use;
		
		for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
		 use.insert(target-(*it));
		
		for(vector<int>::iterator it=nums.begin();it!=nums.end();it++)
		{
			set<int>::iterator p=use.find(*it);
			if(p!=use.end())
			{
				ret.push_back(it-nums.begin());
				
				//可以利用一个struct优化掉这个循环 
				vector<int>::iterator subIt=nums.begin();
				while(subIt!=nums.end() && (subIt==it || (*subIt)+(*it)!=target))
					subIt++;
				
				if(subIt!=nums.end())
				{
					ret.push_back(subIt-nums.begin());
					break;
				}else
					ret.clear();
			}
		}
		return ret;
    }
};
