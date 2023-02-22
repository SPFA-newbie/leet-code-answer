import java.util.*;

class Solution {
    private List<List<String>> res;
    public List<List<String>> solveNQueens(int n) {
        res=new ArrayList();
        List<String> bas=new ArrayList();
        for(int i=0;i<n;i++){
            String aLine="";
            for(int j=0;j<n;j++)
                aLine=aLine+".";
            bas.add(aLine);
        } 
        Work(bas, n, 0);
        return res;
    }
    private void Work(List<String> now, int n, int dep){
        if(dep==n){
            List<String> tres=new ArrayList();
            for(int i=0;i<n;i++)
                tres.add(now.get(i));
            res.add(tres);
            return;
        }
        for(int i=0;i<n;i++){
            if(check(now, n, dep, i)==true){
                now.set(dep, makeString(i, n));
                Work(now, n, dep+1);
                now.set(dep, makeString(n+1, n));
            }
        }
        return;
    }
    private String makeString(int p, int n){
        String ret="";
        for(int i=0;i<n;i++)
            if(i==p)ret=ret+"Q";
                else ret=ret+".";
        return ret;
    }
    private boolean check(List<String> want, int n, int x, int y){
        int tmp=0;
        for(int i=0;i<n;i++)
            if(want.get(x).charAt(i)=='Q')tmp++;
        if(tmp!=0)return false;
        tmp=0;
        for(int i=0;i<n;i++)
            if(want.get(i).charAt(y)=='Q')tmp++;
        if(tmp!=0)return false;
        
        tmp=0;
        int xx=x,yy=y;
        while(xx>=0 && yy>=0){
            if(want.get(xx).charAt(yy)=='Q')tmp++;
            xx--;yy--;
        }
        xx=x;yy=y;
        while(xx<n && yy<n){
            if(want.get(xx).charAt(yy)=='Q')tmp++;
            xx++;yy++;
        }
        if(tmp!=0)return false;

        tmp=0;
        xx=x;yy=y;
        while(xx>=0 && yy<n){
            if(want.get(xx).charAt(yy)=='Q')tmp++;
            xx--;yy++;
        }
        xx=x;yy=y;
        while(xx<n && yy>=0){
            if(want.get(xx).charAt(yy)=='Q')tmp++;
            xx++;yy--;
        }
        if(tmp!=0)return false;
        return true;
    }
}