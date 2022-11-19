class Solution {
public:
    bool canChange(string start, string target) {
        int p1=0,p2=0;
        while(p1<start.length() || p2<target.length())
        {
        	while(p1<start.length() && start[p1]=='_')p1++;
        	while(p2<target.length() && target[p2]=='_')p2++;
        	if(p1==start.length() && p2==target.length())break;else
        	if(p1==start.length() || p2==target.length())return false;else
        	if(start[p1]=='L' && target[p2]=='L' && p1<p2)return false;else
        	if(start[p1]!=target[p2])return false;else
        		p1++,p2++;
		}
		p1=p2=start.length();
		while(p1>=0 || p2>=0)
		{
			while(p1>=0 && start[p1]=='_')p1--;
        	while(p2>=0 && target[p2]=='_')p2--;
        	if(p1==-1 && p2==-1)break;else
        	if(p1==-1 || p2==-1)return false;else
        	if(start[p1]=='R' && target[p2]=='R' && p1>p2)return false;
        	p1--,p2--;
		}
		return true;
    }
};
