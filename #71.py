class Solution:
    def simplifyPath(self, path: str) -> str:
        names = path.split("/")
        res = []
        for name in names:
            if name==".." and len(res)!=0 :
                res.pop()
            elif name!="." and name!=".." and name!="" :
                res.append(name)
        ret=""
        for r in res :
            ret=ret+"/"
            ret=ret+r
        if ret=="" :
            ret="/"
        return ret
