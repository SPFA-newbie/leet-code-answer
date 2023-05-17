int canJump(int* nums, int numsSize){
    int far=0;
    for(int i=0;i<numsSize;i++)
        if(i>far) return 0;
        else if(i+nums[i]>far)
            far=nums[i]+i;
    return 1;
}
