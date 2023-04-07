#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct V{
    int beg;
    map<int, int> len;
    V(int b){beg=b;}
};

inline bool cmp(vector<int> a, vector<int> b) {return a[0]<b[0];}

class Solution {
public:
    vector<V> vs;
    int DFS(int pos, int from, vector<vector<int>>& e) {
        int maxx=0;
        for(int i=vs[pos].beg;i<e.size() && e[i][0]==pos;i++) 
            if(e[i][1]!=from) {
                int t=0;
                if(vs[pos].len.find(e[i][1])!=vs[pos].len.end())
                    t=vs[pos].len[e[i][1]];
                else {
                    t=DFS(e[i][1], pos, e);
                    vs[pos].len[e[i][1]]=t;
                }
                maxx=maxx>t?maxx:t;
            }
        return maxx+1;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n-1;i++) {
            vector<int> t;
            t.push_back(edges[i][1]);
            t.push_back(edges[i][0]);
            edges.push_back(t);
        }
        
        sort(edges.begin(), edges.end(), cmp);
        for(int i=0;i<n;i++)
            vs.push_back(V(edges.size()));
        for(int i=edges.size()-1;i>=0;i--)
            vs[edges[i][0]].beg=i;
        
        int minn=n+1;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            int t=DFS(i, -1, edges);
            if(t==minn) {
                ans.push_back(i);
            }else if(t<minn) {
                minn=t;
                ans.clear();
                ans.push_back(i);
            }
        }
        return ans;            
    }
};