class Solution:
    def isPalindrome(self, s: str) -> bool:
        s=s.lower()
        p=""
        for c in s:
            if (c>='a' and c<='z') or (c>='0' and c<='9'):
                p=p+c
        for i in range(0, len(p)):
            if p[i]!=p[len(p)-i-1]:
                return False
        return True