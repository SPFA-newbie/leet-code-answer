import queue

class Solution:
    def minJumps(self, arr: list[int]) -> int:
        edge={}
        isArr=[]
        dis=[]
        q=queue.SimpleQueue()

        for i in range(0, len(arr)):
            if arr[i] not in edge:
                edge[arr[i]]=queue.SimpleQueue()
            edge[arr[i]].put(i)
            isArr.append(False)
            dis.append(510000)

        def work(now, next):
            if next<0 or next>=len(arr):
                return None
            if now==next:
                return None
            if dis[now]+1<dis[next]:
                dis[next]=dis[now]+1
            if isArr[next]==False:
                isArr[next]=True
                q.put(next)

        dis[0]=0        
        q.put(0)
        while(q.empty()==False):
            now=q.get()
            isArr[now]=True
            work(now, now-1)
            work(now, now+1)
            while(edge[arr[now]].empty()==False):
                next=edge[arr[now]].get()
                work(now, next)
            
        return dis[len(arr)-1]