#include<vector>
#include<algorithm>
using namespace std;

inline bool cmp(int a, int b) {return a>b;}

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> sub;
        int sum=0;
        for(auto i=reward1.begin(),j=reward2.begin(); i!=reward1.end(); i++,j++)
            sub.push_back((*i)-(*j)), sum+=(*j);
        sort(sub.begin(), sub.end(), cmp);
        auto it=sub.begin();
        for(int i=0;i<k;i++,it++)
            sum+=(*it);
        return sum;
    }
};
