#include<vector>
using namespace std;

struct Line{
    int val;
    int len;
    Line(int v, int l){
        val=v;
        len=l;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<Line> line;
        int last=nums[0];
        int len=1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=last) {
                line.push_back(Line(nums[i-1], len));
                len=1;
                last=nums[i];
            }else len++;
        }
        line.push_back(Line(nums[nums.size()-1], len));

        if(line.size()==1)
            return line[0].val==1?line[0].len-1:0;
        int best=0;
        for(int i=0;i<line.size();i++) {
            if(line[i].val==1 && line[i].len>best)best=line[i].len;
            if(line[i].val==0 && line[i].len==1) {
                if(i+1<line.size() && i-1>=0)
                    if(line[i-1].len+line[i+1].len>best)
                        best=line[i-1].len+line[i+1].len;
            }
        }
        return best;
    }
};