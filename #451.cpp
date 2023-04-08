#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct C{
    char c;
    int num;
    C(char cc){c=cc;num=0;}
};

inline bool cmp(C* a, C* b) {return a->num>b->num;}

class Solution {
public:
    map<char, C*> css;
    string frequencySort(string s) {
        for(int i=0;i<s.length();i++) {
            if(css.find(s[i])==css.end()) {
                char tp=s[i];
                C* tpp=new C(s[i]);
                css[tp]=tpp;
            }
            css.find(s[i])->second->num++;
        }
        vector<C*> cs;
        for(auto it=css.begin();it!=css.end();it++)
            cs.push_back(it->second);
        sort(cs.begin(), cs.end(), cmp);
        string ans="";
        for(int i=0;i<cs.size();i++)
            for(int j=0;j<cs[i]->num;j++)
                ans.push_back(cs[i]->c);
        return ans;
    }
};
