public class Solution {
    private List<IList<int>> ans;
    private int len;
    
    public IList<IList<int>> PermuteUnique(int[] nums) {
        int[] times=new int[25];
        for(int i=0;i<nums.Length;i++) {
            times[nums[i]+10]++;
        }
        len=nums.Length;
        ans=new List<IList<int>>();
        Work(times, 0, new List<int>());
        return ans;
    }
    public void Work(int[] times, int dep, List<int> now) {
        if(dep==len) {
            ans.Add(new List<int>(now));
            return;
        }
        for(int i=0;i<25;i++) {
            if(times[i]!=0) {
                now.Add(i-10);
                times[i]--;
                Work(times, dep+1, now);
                times[i]++;
                now.RemoveAt(now.Count-1);
            }
        }
        return;
    }
}