#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

inline bool cmp0(vector<int> a,vector<int> b){return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];}
inline bool cmp1(vector<int> a,vector<int> b){return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];}

struct Tp{
	int id;
	int val;
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
		for(int i=0;i<intervals.size();i++)
			intervals[i].push_back(i);
		
		vector<int> ret;
		for(int i=0;i<intervals.size();i++)
			ret.push_back(-1);
			
		queue<Tp> waitLine;
		sort(intervals.begin(),intervals.end(),cmp1);
		for(int i=0;i<intervals.size();i++)
		{
			Tp node;
			node.id=intervals[i][2];node.val=intervals[i][1];
			waitLine.push(node);
		} 
		
		sort(intervals.begin(),intervals.end(),cmp0);
		for(int i=0;i<intervals.size();i++)
		{
			while(waitLine.empty()==false && intervals[i][0]>=waitLine.front().val)
			{
				ret[waitLine.front().id]=intervals[i][2];
				waitLine.pop();
			}
		}
		return ret;
    }
};
