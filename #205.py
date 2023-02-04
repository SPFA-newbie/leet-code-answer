class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mp={}
        if len(s)!=len(t):
            return False
        for i in range(0, len(s)):
            if s[i] in mp:
                if mp[s[i]]!=t[i]:
                    return False
            else:
                mp[s[i]]=t[i]

        mp={}
        for i in range(0, len(s)):
            if t[i] in mp:
                if mp[t[i]]!=s[i]:
                    return False
            else:
                mp[t[i]]=s[i]
        return True
