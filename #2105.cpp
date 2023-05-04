class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int num=plants.size();
        auto itA=plants.begin(), itB=plants.end();
        itB--;
        int leftA=capacityA, leftB=capacityB;
        int ans=0;

        for(int i=0;i<num/2;i++) {
            if(leftA>=*itA)
                leftA-=*itA;
            else ans++, leftA=capacityA-*itA;
            if(leftB>=*itB)
                leftB-=*itB;
            else ans++, leftB=capacityB-*itB;
            itA++, itB--;
        }
        if(num%2==1) {
            int best=leftA>leftB?leftA:leftB;
            if(best<*itA)
                ans++;
        }
        return ans;
    }
};
