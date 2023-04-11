#include<string>
#include<vector>
#include<set>
using namespace std;

struct P{
    int x, y, d;
    P(int xx, int yy, int dd) {
        x=xx;y=yy;d=dd;
    }
    P tL() {
        return P(x, y, d-1<0?3:d-1);
    }
    P tR() {
        return P(x, y, (d+1)%4);
    }
    P go() {
        if(d==0) return P(x, y+1, d);
        if(d==1) return P(x+1, y, d);
        if(d==2) return P(x, y-1, d);
        return P(x-1, y, d);
    }
    bool operator<(const P& a)const {
        return x==a.x?(y==a.y?d<a.d:y<a.y):x<a.x;
    }
    bool operator>(const P& a)const {
        return x==a.x?(y==a.y?d>a.d:y>a.y):x>a.x;
    }
};

class Solution {
public:
    vector<set<P>> pos;
    bool isRobotBounded(string instructions) {
        for(int i=0;i<instructions.length();i++)
            pos.push_back(set<P>());
        
        P now=P(0, 0, 0);
        int l=instructions.length();
        pos[0].insert(now);
        for(int t=0;t<=l*2;t++)
            for(int i=0;i<l;i++) {
                if(instructions[i]=='G') now=now.go(); else
                if(instructions[i]=='L') now=now.tL(); else
                    now=now.tR();
                if(pos[(i+1)%l].find(now)!=pos[(i+1)%l].end())
                    return true;
                pos[(i+1)%l].insert(now);
            }
        return false;
    }
};