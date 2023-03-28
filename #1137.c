int tribonacci(int n){
    long long t[4];
    t[0]=t[3]=0;t[1]=t[2]=1;
    for(int i=3;i<=n;i++)
        t[i%4]=t[0]+t[1]+t[2]+t[3]-t[i%4];
    return t[n%4];
}