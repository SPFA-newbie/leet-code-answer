class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
		int maxx=0;
		int head=0;
		bool have[256];
		for(int i=0;i<256;i++)
		 have[i]=false;
		
		for(int i=0;i<s.length();i++)
		{
			if(!have[s[i]])have[s[i]]=true;
			else
			{
				maxx=(maxx>i-head?maxx:i-head);
				while(have[s[i]])
				{
					have[s[head]]=false;
					head++;
				}
				have[s[i]]=true;
			}
		}
		maxx=maxx>s.length()-head?maxx:s.length()-head;
		return maxx;
    }
};
