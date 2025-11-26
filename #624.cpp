#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void MaxOption(int num, int pos, int& maxNum, int& maxPos, int& subMaxNum, int& subMaxPos) {
    if (num > maxNum) {
        subMaxPos = maxPos;
        subMaxNum = maxNum;
        maxNum = num;
        maxPos = pos;
        return;
    }
    if (num > subMaxNum) {
        subMaxPos = pos;
        subMaxNum = num;  
    }
    return;
}

void MinOption(int num, int pos, int& minNum, int& minPos, int& subMinNum, int& subMinPos) {
    if (num < minNum) {
        subMinPos = minPos;
        subMinNum = minNum;
        minNum = num;
        minPos = pos;
        return;
    }
    if (num < subMinNum) {
        subMinPos = pos;
        subMinNum = num;  
    }
    return;
}

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxx, maxxPos, subMaxx, subMaxxPos;
        int minn, minnPos, subMinn, subMinnPos;
        minn = subMinn = 100000;
        maxx = subMaxx = -100000;
        maxxPos = minnPos = subMaxxPos = subMinnPos = 0;
        int pos = 0;
        for (auto list: arrays) {
            auto listMin = list.begin();
            auto listMax = list.end();
            listMax--;
            MaxOption(*listMax, pos, maxx, maxxPos, subMaxx, subMaxxPos);
            MinOption(*listMin, pos, minn, minnPos, subMinn, subMinnPos);
            pos++;
        }
        if (minnPos != maxxPos) {
            return maxx - minn;
        }
        return max(maxx - subMinn, subMaxx - minn);
    }
};