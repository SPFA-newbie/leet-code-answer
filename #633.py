class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        r=65536
        l=0
        while(l<=r):
            if l*l+r*r==c: return True
            elif l*l+r*r<c: l+=1
            else: r-=1
        return False