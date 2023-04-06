#include<vector>
#include<string>
#include<set>
using namespace std;

struct IP {
    int ip[4];
    int pos;
    IP(){pos=ip[0]=ip[1]=ip[2]=ip[3]=0;}
    string toString() {
        string s="";
        for(int i=0;i<4;i++) {
            string ts="";
            if(ip[i]==0) 
                ts=ts+"0";
            else {
                int t=ip[i];
                while(t!=0) {
                    ts.push_back(t%10+'0');
                    t/=10;
                }
            }
            for(int j=ts.length()-1;j>=0;j--)
                s.push_back(ts[j]);
            if(i!=3)s.push_back('.');
        }
        return s;
    }
    void add(int n) {
        ip[pos]=n;
        pos++;
    }
};

class Solution {
public:
    set<string> ans;
    void DFS(string& ori, int pos, int now, IP nowIP) {
        if(now>255)return;
        if(nowIP.pos==4) {
            if(pos==ori.length())
                ans.insert(nowIP.toString());
            return;
        }
        if(pos==ori.length()) {
            if(now>=0 && nowIP.pos==3) {
                nowIP.add(now);
                ans.insert(nowIP.toString());
            }
            return;
        }

        if(now==-1) {
            IP next=nowIP;
            now=ori[pos]-'0';
            next.add(now);
            DFS(ori, pos+1, -1, next);
            if(now!=0)
                DFS(ori, pos+1, now, nowIP);
        } else {
            IP next=nowIP;
            next.add(now);
            DFS(ori, pos, -1, next);
            now*=10;
            now+=ori[pos]-'0';
            DFS(ori, pos+1, now, nowIP);
        }
        return;
    }
    vector<string> restoreIpAddresses(string s) {
        DFS(s, 0, -1, IP());
        vector<string> ret;
        ret.assign(ans.begin(), ans.end());
        return ret;
    }
};
