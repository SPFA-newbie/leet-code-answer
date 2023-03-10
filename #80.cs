public class Solution {
    public int RemoveDuplicates(int[] nums) {
        int cpos=1;
        int times=1;
        int last=nums[0];
        for(int i=1;i<nums.Length;i++)
            if(nums[i]==last && times<2) {
                nums[cpos]=last;
                cpos++;
                times++;
            }else if(nums[i]!=last) {
                last=nums[i];
                nums[cpos]=last;
                cpos++;
                times=1;
            }
        return cpos;
    }
}