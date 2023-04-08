class Solution:
    def reverseWords(self, s: str) -> str:
        sc=s.split()
        ans=""
        for i in range(len(sc)-1, -1, -1):
            ans=ans+sc[i]+" "
        return ans[:-1]