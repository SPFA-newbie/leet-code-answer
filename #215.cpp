class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int maxx=-10000,minn=10000;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>maxx)maxx=nums[i];
            if(nums[i]<minn)minn=nums[i];
        }
        vector<int> bin;
        for(int i=minn;i<=maxx;i++)
            bin.push_back(0);
        
        for(int i=0;i<nums.size();i++)
            bin[nums[i]-minn]++;
        
        int pos=maxx-minn;
        while(k>0) {
            k-=bin[pos];
            pos--;
        }
        return pos+minn+1;
    }
};