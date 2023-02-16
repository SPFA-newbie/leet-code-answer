class Solution {
    public int removeDuplicates(int[] nums) {
        int n=0;
        for(int i=1;i<nums.length;i++)
            if(nums[n]!=nums[i]){
                n++;
                nums[n]=nums[i];
            }
        return n+1;
    }
}