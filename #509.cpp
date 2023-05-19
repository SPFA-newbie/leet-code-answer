int fb[50];
int tag=0;

class Solution {
public:
    int fib(int n) {
        if(tag!=0) return fb[n];
        tag=1;
        fb[0]=0;
        fb[1]=1;
        for(int i=2;i<=35;i++)
            fb[i]=fb[i-1]+fb[i-2];
        return fb[n];
    }
};
