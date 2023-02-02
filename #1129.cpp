#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

bool arr[201];
int estart[201];

bool cmp(vector<int>& a, vector<int>& b){return a[0]<b[0];}

int selectAns(int a, int b, int c, int d){
	if(a==-1 && b==-1 && c==-1 && d==-1)
		return -1;
	int best=1e6;
	if(a!=-1 && best>a)best=a;
	if(b!=-1 && best>b)best=b;
	if(c!=-1 && best>c)best=c;
	if(d!=-1 && best>d)best=d;
	return best;
}

void BFS(int n, int start, int* dis, vector< vector<int> >& e){
	queue<int> q;
	q.push(start);
	dis[start]=0;
	arr[start]=true;
	while(!q.empty()){
		int now=q.front();
		for(int i=estart[now];i<e.size()&&e[i][0]==now;i++)
			if(!arr[e[i][1]]){
				dis[e[i][1]]=dis[now]+1;
				arr[e[i][1]]=true;
				q.push(e[i][1]);
			}
		q.pop();
	}
}

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector< vector<int> >& redEdges, vector< vector<int> >& blueEdges) {
        memset(estart, 0, sizeof(estart));
		for(int i=0;i<redEdges.size();i++)redEdges[i][0]+=n;
		for(int i=0;i<blueEdges.size();i++)blueEdges[i][1]+=n;
		vector< vector<int> > e;
		e.insert(e.end(), redEdges.begin(), redEdges.end());
		e.insert(e.end(), blueEdges.begin(), blueEdges.end());
		sort(e.begin(), e.end(), cmp);
        for(int i=e.size()-1;i>=0;i--)
        	estart[e[i][0]]=i;
        
        int dis1[201],dis2[201];
		memset(dis1, -1, sizeof(dis1));
		memset(dis2, -1, sizeof(dis2));
		memset(arr, 0, sizeof(arr));
		BFS(n, 0, dis1, e);
		memset(arr, 0, sizeof(arr));
		BFS(n, n, dis2, e);
        
        vector<int> ans;
        for(int i=0;i<n;i++)
        	ans.push_back(selectAns(dis1[i], dis1[i+n], dis2[i], dis2[i+n]));
        return ans;
    }
};
