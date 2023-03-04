int reverse(int x){
    unsigned ans=0;
    unsigned use=x;
    int t=1;
    if(x<0) {
        t=-1;
        use=((unsigned)(~x))+1;
    }
    while(use!=0) {
        if(ans*10/10!=ans)
            return 0;
        ans*=10;
        if(ans+use%10<ans)
            return 0;
        ans+=use%10;
        use/=10;
        if(t==1 && ans>((unsigned)1<<31)-1)
            return 0;
        if(t==-1 && ans>((unsigned)1<<31))
            return 0;
    }
    return ans*t;
}
