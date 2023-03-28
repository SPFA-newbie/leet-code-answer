inline int Max(int a, int b){return a>b?a:b;}

int rob(int* nums, int numsSize){
    int val[2][2];
    val[0][0]=0;
    val[0][1]=nums[0];
    for(int i=1;i<numsSize;i++) {
        if(i%2==0) {
            val[0][1]=val[1][0]+nums[i];
            val[0][0]=Max(val[1][0], val[1][1]);
        } else {
            val[1][1]=val[0][0]+nums[i];
            val[1][0]=Max(val[0][0], val[0][1]);
        }
    }
    if(numsSize%2==1)return Max(val[0][1], val[0][0]);
    return Max(val[1][1], val[1][0]);
}