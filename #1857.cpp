#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool cmpE(vector<int>& a, vector<int>& b) {return a[0]<b[0];}

int maxC(vector<int>& cn) {
    int ret=0;
    for(int i=0;i<cn.size();i++)
        ret=ret>cn[i]?ret:cn[i];
    return ret;
}
void addC(vector<int>& tar, vector<int>& sub) {
    for(int i=0;i<tar.size();i++)
        tar[i]+=sub[i];
    return;
}
struct V {
    int beg;
    char color;
    bool arr;
    vector<int> cn;
    V(char c) {
        color=c;
        arr=false;
        beg=0;
        for(int i=0;i<26;i++)
            cn.push_back(0);
        cn[color-'a']++;
    }
};

class Solution {
public:
    vector<V> vs;
    vector<bool> ar;
    bool findC(int pos, vector<vector<int>>& e) {
        if(ar[pos]==true)return false;
        if(vs[pos].arr==true)return true;
        
        ar[pos]=true;
        vs[pos].arr=true;
        for(int i=vs[pos].beg;i<e.size() && e[i][0]==pos;i++)
            if(findC(e[i][1], e)==false)
                return false;
        ar[pos]=false;

        return true;
    }
    vector<int>& DFS(int pos, vector<vector<int>>& e) {
        if(vs[pos].arr!=0)
            return vs[pos].cn;
        
        vs[pos].arr=1;
        for(int i=vs[pos].beg;i<e.size() && e[i][0]==pos;i++) {
            vector<int> r=DFS(e[i][1], e);
            r.assign(r.begin(), r.end());
            r[vs[pos].color-'a']++;
            for(int j=0;j<r.size();j++)
                if(r[j]>vs[pos].cn[j])
                    vs[pos].cn[j]=r[j];
        }
        return vs[pos].cn;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        for(int i=0;i<colors.length();i++) {
            vs.push_back(V(colors[i]));
            ar.push_back(false);
        }
        sort(edges.begin(), edges.end(), cmpE);
        for(int i=edges.size()-1;i>=0;i--)
            vs[edges[i][0]].beg=i;

        for(int i=0;i<vs.size();i++)
            if(vs[i].arr==0)
                if(findC(i, edges)==false)
                    return -1;

        for(int i=0;i<vs.size();i++)
            vs[i].arr=false;

        int ans=0;        
        for(int i=0;i<vs.size();i++) {
            int best=maxC(DFS(i, edges));
            ans=ans>best?ans:best;
        }
        return ans;
    }
};