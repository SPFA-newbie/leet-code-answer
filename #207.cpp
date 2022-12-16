#include<vector>
using namespace std;


struct Vertax{
	vector<int> to;
	bool beg;
	bool end;
};

Vertax v[110000];

bool DFS(int pos)
{
	if(v[pos].end!=0)return true;
	if(v[pos].beg!=0)return false;
	
	bool res=true;
	v[pos].beg=true;
	for(int i=0;i<v[pos].to.size();i++)
		res&=DFS(v[pos].to[i]);
	v[pos].end=true;
	return res;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		
		for(int i=0;i<numCourses;i++)
		{
			v[i].to.clear();
			v[i].beg=false;
			v[i].end=false;
		}
		for(int i=0;i<prerequisites.size();i++)
		{
			v[prerequisites[i][1]].to.push_back(prerequisites[i][0]);
		}
		
		int flag=0;
		for(int i=0;i<numCourses;i++)
			if(v[i].beg==false)
				if(DFS(i)==false)
					return false;
		return true;		
    }	
};
