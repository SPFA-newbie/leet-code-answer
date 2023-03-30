#include<vector>
#include<list>
using namespace std;

struct Ele{
    int val;
    int pos;
    Ele(int v, int p){
        val=v;
        pos=p;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<Ele> q;
        vector<int> ans;
        int bt=0;
        for(int i=0;i<nums.size();i++) {
            if(i>=k-1 && q.front().pos<i-k+1)
                q.pop_front();
            while(q.empty()==false && nums[i]>=q.back().val)
                q.pop_back();
            q.push_back(Ele(nums[i], i));
            if(i>=k-1)
                ans.push_back(q.front().val);
        }
        return ans;        
    }
};
