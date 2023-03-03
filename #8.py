class Solution:
    def myAtoi(self, s: str) -> int:
        s=s.lstrip()
        if len(s)==0:
            return 0
        n=0
        t=1
        c=s[0]
        i=0
        if c=='-':
            t=-1
            if len(s)==1:
                return 0
            c=s[1]
            i=1
        elif c=='+':
            if len(s)==1:
                return 0
            c=s[1]
            i=1
        while(c>='0' and c<='9'):
            n=n*10
            n=n+int(c)
            i=i+1
            if i>=len(s):
                break
            c=s[i]
        n=n*t
        if n>(1<<31)-1:
            n=(1<<31)-1
        elif n<-(1<<31):
            n=-(1<<31)
        return n