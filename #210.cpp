#include<vector>
#include<algorithm>
using namespace std;

struct Vertax{
	int id;
	vector<int> to;
	int beg;
	int end;
};

Vertax v[110000];

inline bool cmp(Vertax a,Vertax b){return a.end>b.end;}

bool DFS(int pos,int & flag)
{
	if(v[pos].end!=0)return true;
	if(v[pos].beg!=0)return false;
	
	flag++;
	
	bool res=true;
	v[pos].beg=flag;
	for(int i=0;i<v[pos].to.size();i++)
		res&=DFS(v[pos].to[i],flag);
	
	flag++;
	v[pos].end=flag;
	return res;
}

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		
		for(int i=0;i<numCourses;i++)
		{
			v[i].id=i;
			v[i].to.clear();
			v[i].beg=0;
			v[i].end=0;
		}
		for(int i=0;i<prerequisites.size();i++)
		{
			v[prerequisites[i][1]].to.push_back(prerequisites[i][0]);
		}
		
		vector<int> res;
		
		int flag=0;
		for(int i=0;i<numCourses;i++)
			if(v[i].beg==false)
				if(DFS(i,flag)==false)
					return res;
		
		sort(v,v+numCourses,cmp);
		for(int i=0;i<numCourses;i++)
			res.push_back(v[i].id);
		
		return res;	
    }
};
