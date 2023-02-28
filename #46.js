/**
 * @param {number[]} nums
 * @return {number[][]}
 */

var ans=[];

var permute = function(nums) {
    ans=[];
    var beUse=[];
    for(var i=0;i<nums.length;i++)
        beUse[i]=false;
    work(nums, beUse, 0, []);
    return ans;
};

function work(nums, beUse, dep, now) {
    if(dep==nums.length) {
        ans[ans.length]=clone(now);
    }

    for(var i=0;i<nums.length;i++) {
        if(beUse[i]==false) {
            beUse[i]=true;
            now[dep]=nums[i];
            work(nums, beUse, dep+1, now);
            beUse[i]=false;
        }
    }
    return;
}

function clone(arr) {
    var newArr=[];
    for(var i=0;i<arr.length;i++) {
        newArr[i]=arr[i];
    }
    return newArr;
}