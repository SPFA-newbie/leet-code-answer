public class Solution {
    private int[] inClass;
    public int[] FindRedundantConnection(int[][] edges) {
        int maxV=0;
        foreach (int[] e in edges) {  
           if(e[0]>maxV)maxV=e[0];
           if(e[1]>maxV)maxV=e[1]; 
        }

        inClass=new int[maxV+1];
        for(int i=1;i<=maxV;i++)
            inClass[i]=i;
        
        foreach(int[] e in edges) 
        {
            if(find(e[0])==find(e[1]))
                return e;
            union(e[0],e[1]);
        }
        return edges[0];
        
    }
    private int find(int p){
        return inClass[p]==p?p:find(inClass[p]);
    }
    private void union(int a, int b){
        inClass[find(a)]=inClass[find(b)];
        return;
    }
}