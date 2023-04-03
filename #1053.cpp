class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int best;
        int bp;
        for(int i=arr.size()-1;i>=0;i--) {
            best=0;
            bp=-1;
            for(int j=i+1;j<arr.size();j++)
                if(arr[j]<arr[i] && arr[j]>best)
                    best=arr[j], bp=j;
            if(bp!=-1) {
                arr[bp]=arr[i];
                arr[i]=best;
                return arr;
            }    
        }
        return arr;
    }
};
