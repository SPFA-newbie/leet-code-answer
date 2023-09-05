#include<vector>
using namespace std;

unsigned long long bin[3][110000];

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int len=0;
        for(auto it=nums.begin();it!=nums.end();it++)
            bin[0][len]=(*it+(long long)1e9), len++;
        
        unsigned long long *a, *b, *c;
        int bl=0, cl=0;
        a=bin[0], b=bin[1], c=bin[2];
        for(int i=0;i<32;i++) {
            bl=0, cl=0;
            for(int j=0;j<len;j++)
                if((a[j]>>i)%2==0) b[bl]=a[j], bl++;
                    else c[cl]=a[j], cl++;
            for(int j=0;j<cl;j++)
                b[bl]=c[j], bl++;
            unsigned long long *tmp=a;
            a=b, b=tmp;
        }
        a=b;
        int maxlen=0, nowlen=1;
        for(int i=1;i<len;i++)
            if(a[i]-a[i-1]==1) nowlen++;else
            if(a[i]!=a[i-1]) {
                maxlen=(maxlen>nowlen?maxlen:nowlen);
                nowlen=1;
            }
                
        if(nowlen>maxlen) maxlen=nowlen;
        return maxlen;
    }
};
