class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int t=logs[0][1];
        int ans=logs[0][0];
        auto it=logs.begin();
        it++;
        for(;it!=logs.end();it++) {
            auto pit=it;
            pit--;
            if((*it)[1]-(*pit)[1]>t)
                ans=(*it)[0], t=(*it)[1]-(*pit)[1];
            else if((*it)[1]-(*pit)[1]==t && (*it)[0]<ans)
                ans=(*it)[0];
        }
        return ans;
    }
};
