class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int maxx=nums.size();
        for(int i=0;i<maxx;i++) {
            if(nums[i]==val) {
                maxx--;
                while(maxx>i && nums[maxx]==val)maxx--;
                if(maxx==i) return maxx;
                nums[i]=nums[maxx];
            }
        }
        return maxx;
    }
};
