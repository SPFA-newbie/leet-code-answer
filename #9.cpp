class Solution {
public:
    bool isPalindrome(int x) {
		if(x<0)return false;
		int s1[16],s2[16];
		int p1=0,p2=15;
		while(x!=0)
		{
			int a=x%10;
			x/=10;
			s1[p1]=a;
			s2[p2]=a;
			p1++;
			p2--;
		}
		for(int i=0,j=p2+1;i<p1;i++,j++)
			if(s1[i]!=s2[j])
				return false;
		return true;
    }
};
