/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    if(nums.length==1)
        return 0;
    minStep=new Array();
    for(var i=0;i<nums.length;i++)
        minStep[i]=100001;
    minStep[0]=0;
    for(var i=0;i<nums.length;i++)
        for(var j=1;i+j<nums.length && j<=nums[i];j++)
            if(minStep[i+j]>minStep[i]+1)
                minStep[i+j]=minStep[i]+1;
    return minStep[nums.length-1];
};