class Solution {
public:
    int idealArrays(int n, int maxValue) {
        
		p[0][1]=1;
		for(int i=1;i<=maxValue;i++)
		 p[0][i]=1;
		last=0;
		
		for(int i=1;i<=maxValue;i++)
		 len[i]=0;
		 
		for(int i=1;i<=maxValue;i++)
		 for(int j=1;j<=i;j++)
		  if(i%j==0)
		  {
		  	len[i]++;
		  	from[i][len[i]]=j;
		  }
        
        for(int i=2;i<=n;i++,last=now())
         for(int j=1;j<=maxValue;j++)
          for(int k=1;k<=len[j];k++)
          {
        	if(k==1)p[now()][j]=p[last][from[j][k]];else
        	{
        	 	p[now()][j]+=p[last][from[j][k]];
        	 	p[now()][j]%=m;
			}
		  }
		
		last=now();
		long long ret=0;
		for(int i=1;i<=maxValue;i++)
		{
			ret+=p[now()][i];
			ret%=m;
		}
		return ret;         
    }
private:
	long long p[2][10001];
	int len[10001];
	int from[10001][101];
	long long m=1000000007;
	int last;
	int now(){return (last+1)%2;}
	
	
};

Solution s;

int main()
{
	
	s.idealArrays(10000,10000);
	return 0;
}
