#include<string>
#include<vector>
using namespace std;

bool use[10][10];
bool check(int x,int y)
{
	for(int i=0;i<10;i++)
	{
		if(i!=x && use[i][y])return false;
		if(i!=y && use[x][i])return false;
	}
	int sx=x,sy=y;
	while(sx!=0 && sy!=0)sx--,sy--;
	while(sx<10 && sy<10)
	{
		if(sx!=x && sy!=y && use[sx][sy])
			return false;
		sx++,sy++;
	}
	sx=x,sy=y;
	while(sx!=0 && sy!=9)sx--,sy++;
	while(sx<10 && sy>=0)
	{
		if(sx!=x && sy!=y && use[sx][sy])
			return false;
		sx++,sy--;
	}
	return true;
}

vector< vector<string> > res;

void Print(int n)
{
	vector<string> sres;
	for(int i=0;i<n;i++)
	{
		string line="";
		for(int j=0;j<n;j++)
			if(use[i][j])line.append("Q");
				else line.append(".");
		sres.push_back(line);
	}
	res.push_back(sres);
	return;
}

void Work(int x, int n)
{
	if(x==n)
	{
		Print(n);
		return;
	}
	for(int i=0;i<n;i++)
	{
		use[x][i]=true;
		if(check(x,i)==true)
			Work(x+1,n);
		use[x][i]=false;
	}
	return;
}

class Solution {
public:
    vector< vector<string> > solveNQueens(int n) {
		res.clear();
		Work(0,n);
		return res;
    }
};
