/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    var arr=Array();
    for(var i=0;i<nums.length;i++)
        arr[i]=false;
    arr[0]=true;
    for(var i=0;i<nums.length;i++)
        if(arr[i]==true)
            for(var j=i+1;j<nums.length && j<=nums[i]+i;j++)
                arr[j]=true;
    return arr[nums.length-1];
    // return arr[3];
};