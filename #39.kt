class Solution {
    fun combinationSum(candidates: IntArray, target: Int): List<List<Int>> {
        var ret:MutableList<List<Int>> = mutableListOf();
        var bin:MutableList<Int> = mutableListOf();
        work(candidates, 0, 0, target, bin, ret);
        return ret.toList();
    }
    fun work(arr: IntArray, pos: Int, sum: Int, tar: Int, now: MutableList<Int>, ans: MutableList<List<Int>>) {
        if(sum==tar) {
            ans.add(now.toList());
            return;
        }
        if(pos==arr.count())
            return;
        var tmp=sum;
        var tlist=now.toMutableList();
        while(tmp<=tar) {
            work(arr, pos+1, tmp, tar, tlist, ans);
            tlist.add(arr[pos]);
            tmp+=arr[pos];
        }
        return;
    }
}