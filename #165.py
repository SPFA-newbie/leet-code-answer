class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1=version1.split(".")
        v2=version2.split(".")
        vn1=[]
        vn2=[]
        for vp in v1:
            vn1.append(int(vp))
        for vp in v2:
            vn2.append(int(vp))
        while len(vn1)!=len(vn2):
            if len(vn1)>len(vn2):
                vn2.append(0)
            else:
                vn1.append(0)
        
        for i in range(len(vn1)):
            if vn1[i]>vn2[i] :
                return 1
            if vn1[i]<vn2[i] :
                return -1
        return 0
