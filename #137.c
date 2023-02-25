int singleNumber(int* nums, int numsSize){
    long long ts[32];
    long long nts[32];
    for(int i=0;i<32;i++)
        ts[i]=nts[i]=0;
    for(int i=0;i<numsSize;i++) {
        nums[i]>=0?getT((long long)nums[i], ts):getNT((long long)nums[i], nts);
    }
    long long ans=0;
    for(int i=0;i<32;i++) {
        ans+=((ts[i]%3)<<i);
    }
    if(ans==0)
        for(int i=0;i<32;i++) {
            ans-=((nts[i]%3)<<i);
        } 
    return ans;
}

void getT(long long n, long long* ts) {
    int i=0;
    while(n!=0) {
        if(n%2)ts[i]++;
        n/=2;
        i++;    
    }
    return;
}

void getNT(long long n, long long* ts) {
    long long i=0;
    n=-n;
    while(n!=0) {
        if(n%2)ts[i]++;
        n/=2;
        i++;    
    }
    return;
}