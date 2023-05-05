#include<set>
#include<vector>
#include<algorithm>
using namespace std;

inline void Swap(int &a, int &b) {a+=b, b=(a-b), a-=b;}
inline int Max(int a, int b) {return a>b?a:b;}

struct Three{
    int a, b, c;
    Three(int x, int y, int z) {
        a=x, b=y, c=z;
        if(a<b)Swap(a, b);
        if(b<c)Swap(b, c);
        if(a<b)Swap(a, b);
        if(b<c)Swap(b, c);
    }
    vector<int> toVector() {
        vector<int> ret;
        ret.push_back(a);
        ret.push_back(b);
        ret.push_back(c);
        return ret;
    }
};

class Solution {
public:
    set<vector<int>> s;
    multiset<int> bin;
    vector<vector<int>> threeSum(vector<int>& nums) {
        for(auto it=nums.begin();it!=nums.end();it++)
            bin.insert(*it);

        vector<vector<int>> ans;
        // sort(nums.begin(), nums.end());
        // auto positive=nums.begin();
        // while(positive!=nums.end() && *positive<0) positive++;
        // if(positive==nums.end())
        //     return ans;
        
        for(auto i=nums.begin();i!=nums.end();i++) {
            if(i!=nums.begin() && *i==*(i-1))
                continue;
            for(auto j=i+1;j!=nums.end();j++) {
                if(j!=i+1 && *j==*(j-1))
                    continue;
                int k=-(*i+*j);
                int nedt=1;
                if(k==*i) nedt++;
                if(k==*j) nedt++;
                if(bin.count(k)>=nedt)
                    s.insert(Three(*i, *j, k).toVector());
        
            }
        }
            
        ans.assign(s.begin(), s.end());
        return ans;
    }
};
