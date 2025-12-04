#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

class Solution {
public:
    inline pair<int, int> posMove(pair<int, int> pos, int x, int y) {
        return make_pair(pos.first + x, pos.second + y);
    }
    inline int posMap(pair<int, int> pos) {
        return pos.first * 10000 + pos.second;
    }
    int minKnightMoves(int x, int y) {
        queue<pair<pair<int, int>, int>> q;
        unordered_set<int> arr;
        pair<int, int> tar = make_pair(x, y);
        q.push(make_pair(make_pair(0, 0), 0));
        while (!q.empty()) {
            int dis = q.front().second;
            pair<int, int> pos = q.front().first;
            q.pop();
            if (arr.find(posMap(pos)) != arr.end()) continue;
            arr.insert(posMap(pos));
            if (pos == tar) return dis;
            pair<int, int> newPos;
            newPos = posMove(pos, 1, 2);
            if (arr.find(posMap(newPos)) == arr.end()) q.push(make_pair(newPos, dis + 1));
            newPos = posMove(pos, -1, 2);
            if (arr.find(posMap(newPos)) == arr.end()) q.push(make_pair(newPos, dis + 1));
            newPos = posMove(pos, 1, -2);
            if (arr.find(posMap(newPos)) == arr.end()) q.push(make_pair(newPos, dis + 1));
            newPos = posMove(pos, -1, -2);
            if (arr.find(posMap(newPos)) == arr.end()) q.push(make_pair(newPos, dis + 1));
            newPos = posMove(pos, 2, 1);
            if (arr.find(posMap(newPos)) == arr.end()) q.push(make_pair(newPos, dis + 1));
            newPos = posMove(pos, -2, 1);
            if (arr.find(posMap(newPos)) == arr.end()) q.push(make_pair(newPos, dis + 1));
            newPos = posMove(pos, 2, -1);
            if (arr.find(posMap(newPos)) == arr.end()) q.push(make_pair(newPos, dis + 1));
            newPos = posMove(pos, -2, -1);
            if (arr.find(posMap(newPos)) == arr.end()) q.push(make_pair(newPos, dis + 1));
        }
        return 0;
    }
};