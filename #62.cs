public class Solution {
    public int UniquePaths(int m, int n) {
        int[,] nums=new int[2,n];
        bool now=true;
        for(int i=0;i<n;i++)
            nums[0,i]=1;
        for(int i=1;i<m;i++) {
            nums[now?1:0,0]=nums[now?0:1,0];
            for(int j=1;j<n;j++)
                nums[now?1:0,j]=nums[now?1:0,j-1]+nums[now?0:1,j];
            now=(!now);
        }
        return nums[now?0:1,n-1];
    }
}