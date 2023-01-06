class Solution {
public:
    int countEven(int num) {
      	int ans=num/10*5;
      	if(ans>0)ans--;
		int start=num/10*10;
		if(start==0)start++;
		for(int i=start;i<=num;i++)
		{
			int t=0;
			int tmp=i;
			while(tmp!=0){
				t+=(tmp%10);
				tmp/=10;
			}
			if(t%2==0)ans++;
		}
		return ans;
    }
};
