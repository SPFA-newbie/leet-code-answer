#include<vector>
using namespace std;

inline int testBack(int* sum, int i, int k) {return k-i*2>=0?sum[k-i*2]:0;}

class Solution {
public:
    int rsum[210000], lsum[210000];
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        auto lmid=fruits.begin();
        int zeroNum=0;
        bool leftStart=false;
        if(fruits[0][0]>=startPos) {
            leftStart=true;
            if(fruits[0][0]==startPos)
                zeroNum=fruits[0][1];
        }
        while(lmid!=fruits.end() && (*lmid)[0]<startPos) lmid++;
        auto rmid=lmid;

        if(lmid!=fruits.end() && !leftStart){
            if((*lmid)[0]==startPos) zeroNum=(*rmid)[1], rmid++;
            if(lmid!=fruits.begin())lmid--;
        }else if(!leftStart)lmid--;
        else if(zeroNum!=0) rmid++;

        auto it=rmid;
        rsum[0]=lsum[0]=0;
        for(int i=1;i<=k;i++)
            if(it!=fruits.end() && (*it)[0]==startPos+i)
                rsum[i]=rsum[i-1]+(*it)[1], it++;
            else rsum[i]=rsum[i-1];
        
        it=lmid;
        bool st=false;
        for(int i=1;i<=k;i++)
            if(leftStart==false && st==false && (*it)[0]==startPos-i) {
                if(it==fruits.begin()) st=true;
                lsum[i]=lsum[i-1]+(*it)[1];
                if(!st) it--;
            }
                
            else lsum[i]=lsum[i-1];
        
        int best=0;
        for(int i=1;i<=k;i++)
            if(lsum[i]+testBack(rsum, i, k)>best)
                best=lsum[i]+testBack(rsum, i, k);
        for(int i=1;i<=k;i++)
            if(rsum[i]+testBack(lsum, i, k)>best)
                best=rsum[i]+testBack(lsum, i, k);
                
        best+=zeroNum;
        return best;        
    }
};
