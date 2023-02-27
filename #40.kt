class Solution {
    fun combinationSum2(candidates: IntArray, target: Int): List<List<Int>> {
        var use:IntArray=IntArray(51, {i->0});
        for(i in candidates.indices) {
            use[candidates[i]]++;
        }

        var ans:MutableList<List<Int>> = mutableListOf();
        var aans:MutableList<Int> = mutableListOf();
        work(use, 1, 0, target, aans, ans);
        return ans.toList();
    }
    fun work(arr:IntArray, pos:Int, sum:Int, tar:Int, now:MutableList<Int>, ans:MutableList<List<Int>>) {
        if(pos>50)return;
        if(sum>tar)return;
        if(sum==tar) {
            ans.add(now.toList());
            return;
        }

        if(arr[pos]==0) {
            work(arr, pos+1, sum, tar, now, ans);
            return;
        }

        work(arr, pos+1, sum, tar, now, ans);

        var tmpSum=sum;
        var tmpNow=now.toMutableList();
        var useNum=0;
        while(tmpSum<tar && useNum<arr[pos]) {
            tmpSum+=pos;
            tmpNow.add(pos);
            useNum++;
            work(arr, pos+1, tmpSum, tar, tmpNow, ans);
        }
        return;

        
    }
}