#include<vector>
using namespace std;

inline int Max(int a, int b) {return a>b?a:b;}
inline int Best(int a, int b) {
    if(b<=0) return a;
    if(a<=0) return b;
    return a<b?a:b;
}

class Solution {
public:
    int rmax[350][350];
    int val[15][350];
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d>jobDifficulty.size()) return -1;

        int pi,pj;
        pi=pj=0;
        for(auto i=jobDifficulty.begin();i!=jobDifficulty.end();i++) {
            pj=pi;
            for(auto j=i;j!=jobDifficulty.end();j++) {
                rmax[pi][pj]=(pi!=pj?Max(rmax[pi][pj-1], *j):*j);
                pj++;
            }
            pi++;
        }

        for(int i=0;i<jobDifficulty.size()-d+1;i++)
        	val[1][i]=rmax[0][i];
		
		for(int i=2;i<=d;i++)
            for(int j=i-1;j<jobDifficulty.size()-(d-i);j++)
                for(int k=i-2;k<j;k++)
                    val[i][j]=Best(val[i-1][k]+rmax[k+1][j], val[i][j]);
		
        return val[d][jobDifficulty.size()-1];
    }
};
