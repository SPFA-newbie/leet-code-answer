#include<vector>
#include<cstring>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector< vector<char> >& board) {		
		bool checker[9];
		for(int i=0;i<9;i++)
		{
			memset(checker,0,sizeof(checker));
			for(int j=0;j<9;j++)
			{
				if(board[i][j]!='.')
				{
					if(checker[board[i][j]-'1'])
						return false;
					checker[board[i][j]-'1']=true;	
				}
			}
		}
		for(int i=0;i<9;i++)
		{
			memset(checker,0,sizeof(checker));
			for(int j=0;j<9;j++)
			{
				if(board[j][i]!='.')
				{
					if(checker[board[j][i]-'1'])
						return false;
					checker[board[j][i]-'1']=true;
				}
			}
		}
		for(int i=0;i<9;i++)
		{
			memset(checker,0,sizeof(checker));
			for(int j=0;j<9;j++)
			{
				if(board[(i/3)*3+(j/3)][(i%3)*3+(j%3)]!='.')
				{
					if(checker[board[(i/3)*3+(j/3)][(i%3)*3+(j%3)]-'1'])
						return false;
					checker[board[(i/3)*3+(j/3)][(i%3)*3+(j%3)]-'1']=true;
				}
			}
		}
		return true;
    }
};
