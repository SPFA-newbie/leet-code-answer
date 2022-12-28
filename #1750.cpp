#include<string>
using namespace std; 

class Solution {
public:
    int minimumLength(string s) {
		int head=0,tail=s.length()-1;
		while(head!=tail && s[head]==s[tail])
		{
			char c=s[head];
			while(head!=tail && s[head]==c)head++;
			if(head==tail)return 0;
			while(head!=tail && s[tail]==c)tail--;
			if(head==tail)return 1;
		}
		
		return tail+1-head;
    }
};
