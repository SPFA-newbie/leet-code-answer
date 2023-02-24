/**
 * @param {number[]} cards
 * @return {boolean}
 */
var judgePoint24 = function(cards) {
    return work(cards);
};

function work(arr) {
    if(arr.length==1) {
        if(arr[0]-24>-0.001 && arr[0]-24<0.001)return true;
            else return false;
    }

    for(var i=0;i<arr.length;i++)
        for(var j=0;j<arr.length;j++)
            if(i!=j){
                var newArr=new Array();
                for(var k=0;k<arr.length;k++){
                    if(k!=i && k!=j)
                        newArr[newArr.length]=arr[k];
                }
                newArr[arr.length-2]=arr[i]+arr[j];
                if(work(newArr)==true)return true;
                newArr[arr.length-2]=arr[i]-arr[j];
                if(work(newArr)==true)return true;
                newArr[arr.length-2]=arr[i]*arr[j];
                if(work(newArr)==true)return true;
                newArr[arr.length-2]=arr[i]/arr[j];
                if(work(newArr)==true)return true;
            }
    return false;
}