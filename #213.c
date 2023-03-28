inline int Max(int a, int b){return a>b?a:b;}

int rob(int* nums, int numsSize){
    if(numsSize==1)return nums[0];
    //0=xx 1=xv 2=vx 3=vv
    int val[2][4];
    val[0][0]=val[0][1]=val[0][2]=0;
    val[0][3]=nums[0];
    for(int i=1;i<numsSize;i++) {
        if(i%2==0) {
            val[0][1]=val[1][0]+nums[i];
            val[0][0]=Max(val[1][0], val[1][1]);
            val[0][3]=val[1][2]+nums[i];
            val[0][2]=Max(val[1][2], val[1][3]);
        } else {
            val[1][1]=val[0][0]+nums[i];
            val[1][0]=Max(val[0][0], val[0][1]);
            val[1][3]=val[0][2]+nums[i];
            val[1][2]=Max(val[0][2], val[0][3]);
        }
    }
    if(numsSize%2==1)return Max(Max(val[0][1], val[0][0]), val[0][2]);
    return Max(Max(val[1][1], val[1][0]), val[1][2]);
}