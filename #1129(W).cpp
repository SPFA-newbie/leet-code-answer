#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

bool barr[101];
bool rarr[101];
int bstart[101];
int rstart[101];
int bes[101],res[101];

bool cmp(vector<int>& a, vector<int>& b){return a[0]<b[0];}

void bBFS(vector<vector<int> >& e1, vector<vector<int> >& e2){
	queue<int> q;
	bool flag=true;
	if(e1.size()==0)return;
	q.push(0);
	bstart[0]=0;
	while(!q.empty()){
		int now=q.front();
		if(flag){
			if(e1.size()!=0){
				for(int i=bes[now];i<e1.size()&&e1[i][0]==now;i++)
					if(!barr[e1[i][1]]){
						barr[e1[i][1]]=true;
						q.push(e1[i][1]);
						if(bstart[e1[i][1]]==-1 && e1[i][1]!=0)
							bstart[e1[i][1]]=bstart[now]+1;
					}
			}
		}else{
			if(e2.size()!=0){
				for(int i=res[now];i<e2.size()&&e2[i][0]==now;i++)
					if(!rarr[e2[i][1]]){
						rarr[e2[i][1]]=true;
						q.push(e2[i][1]);
						if(bstart[e2[i][1]]==-1 && e2[i][1]!=0)
							bstart[e2[i][1]]=bstart[now]+1;
					}
			}
		}
		flag=(!flag);
		q.pop();
	}
}

void rBFS(vector<vector<int> >& e1, vector<vector<int> >& e2){
	queue<int> q;
	bool flag=false;
	if(e2.size()==0)return;
	q.push(0);
	rstart[0]=0;
	while(!q.empty()){
		int now=q.front();
		if(flag){
			if(e1.size()!=0){
				for(int i=bes[now];i<e1.size()&&e1[i][0]==now;i++)
					if(!barr[e1[i][1]]){
						barr[e1[i][1]]=true;
						q.push(e1[i][1]);
						if(rstart[e1[i][1]]==-1 && e1[i][1]!=0)
							rstart[e1[i][1]]=rstart[now]+1;
					}
			}
		}else{
			if(e2.size()!=0){
				for(int i=res[now];i<e2.size()&&e2[i][0]==now;i++)
					if(!rarr[e2[i][1]]){
						rarr[e2[i][1]]=true;
						q.push(e2[i][1]);
						if(rstart[e2[i][1]]==-1 && e2[i][1]!=0)
							rstart[e2[i][1]]=rstart[now]+1;
					}
			}
		}
		flag=(!flag);
		q.pop();
	}
}

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int> >& redEdges, vector<vector<int> >& blueEdges) {
        sort(redEdges.begin(), redEdges.end(), cmp);
        sort(blueEdges.begin(), blueEdges.end(), cmp);
        memset(barr, 0, sizeof(barr));
        memset(rarr, 0, sizeof(rarr));
        memset(bstart, -1, sizeof(bstart));
        memset(rstart, -1, sizeof(rstart));
        for(int i=blueEdges.size()-1;i>=0;i--)
        	bes[blueEdges[i][0]]=i;
        for(int i=redEdges.size()-1;i>=0;i--)
        	res[redEdges[i][0]]=i;
        bBFS(blueEdges, redEdges);
        memset(barr, 0, sizeof(barr));
        memset(rarr, 0, sizeof(rarr));
        rBFS(blueEdges, redEdges);
        vector<int> ans;
        for(int i=0;i<n;i++)
        	if(bstart[i]==-1 && rstart[i]==-1)
        		ans.push_back(-1);
			else if(bstart[i]<rstart[i] && bstart[i]!=-1)
				ans.push_back(bstart[i]);
			else ans.push_back(rstart[i]);
        return ans;
    }
};
