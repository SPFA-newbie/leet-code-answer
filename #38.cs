public class Solution {
    public string CountAndSay(int n) {
        string s="1";
        for(int i=1;i<n;i++) {
            s=Work(s);
        }
        return s;
    }
    public string Work(string s) {
        int num=1;
        char now=s[0];
        string ret="";
        for(int i=1;i<s.Length;i++) {
            if(s[i]==now) {
                num++;
            }else {
                ret+=num.ToString()+now;
                now=s[i];
                num=1;
            }
        }
        ret+=num.ToString()+now;
        return ret;
    }
}