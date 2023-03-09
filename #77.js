/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
 var ret;
var combine = function(n, k) {
    ret=Array();
    work(n, k, Array(), 0, 0);
    return ret;
};

function work(n, k, now, pos, dep) {
    if(dep==k) {
        ret[ret.length]=[...now];
        return;
    }
    if(pos+(k-dep)>n+1)return;
    for(var i=pos+1;i<=n;i++) {
        now[dep]=i;
        work(n, k, now, i, dep+1);
    }
    return;        
}