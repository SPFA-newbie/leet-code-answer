#include<vector>
using namespace std;

class Solution {
public:
    int h[1001];
    int hIndex(vector<int>& citations) {
        for(int i=0;i<=1000;i++)
            h[i]=0;
        for(int i=0;i<citations.size();i++)
            h[citations[i]]++;
        
        int sum=0;
        for(int i=1000;i>=0;i--) {
            if(sum==i) return i;
            sum+=h[i];
            if(sum>=i) return i;
        }
        return 0;
    }
};
