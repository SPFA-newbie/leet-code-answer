#include<vector>
using namespace std;

#include<algorithm>

class Solution {
public:
    int fillCups(vector<int>& amount) {
        int ret=0;
		sort(amount.begin(),amount.end());
		if(amount[0]+amount[1]>amount[2])
		{
			ret+=amount[2];
//			ret+=(amount[1]-amount[0]);
			amount[2]-=(amount[1]-amount[0]);
			ret+=(amount[0]*2-amount[2])/2;
			if((amount[0]*2-amount[2])%2==1)
				ret++;
		}else
		{
			ret=amount[2];
		}
		return ret;
    }
};
