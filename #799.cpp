double p[120][120];
inline double cut(double x){if(1.0-x<1e-16)return x-1.0;return 0;}

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
		p[0][0]=poured;
		for(int i=1;i<=query_row;i++)
		 for(int j=0;j<=i;j++)
		  if(j==0)p[i][j]=(cut(p[i-1][j]))/2;else
		  if(i==j)p[i][j]=(cut(p[i-1][j-1]))/2;else
		   p[i][j]=((cut(p[i-1][j-1]))/2)+((cut(p[i-1][j]))/2);
		
		if(p[query_row][query_glass]>1)return 1;
		return p[query_row][query_glass];	 
    }
};
