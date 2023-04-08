#include<vector>
#include<string>
#include<algorithm>
using namespace std;

inline bool cmp(string a, string b) {
    return a+b>b+a;
}

class Solution {
public:
    vector<string> str;
    string largestNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            str.push_back(to_string(nums[i]));
        sort(str.begin(), str.end(), cmp);
        string ans="";
        for(int i=0;i<str.size();i++)
            ans=ans+str[i];
        if(ans[0]=='0')
            ans="0";
        return ans;
    }
};
