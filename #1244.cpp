#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
};

class Leaderboard {
public:
    map<int, int> idScoreMap; 
    set<pair<int, int>, cmp> idScoreSet;
    Leaderboard() {
        idScoreMap.clear();
        idScoreSet.clear();
    }
    
    void addScore(int playerId, int score) {
        auto mapIt = idScoreMap.find(playerId);
        if (mapIt == idScoreMap.end()) {
            pair<int, int> idScore = make_pair(playerId, score);
            idScoreMap.insert(idScore);
            idScoreSet.insert(idScore);
        } else {
            idScoreSet.erase(*mapIt);
            mapIt->second += score;
            idScoreSet.insert(*mapIt);
        }
    }
    
    int top(int K) {
        int sum = 0;
        for (auto it = idScoreSet.begin(); it != idScoreSet.end() && K != 0; it++, K--) {
            sum += it->second;
        }
        return sum;
    }
    
    void reset(int playerId) {
        auto mapIt = idScoreMap.find(playerId);
        idScoreSet.erase(*mapIt);
        idScoreMap.erase(mapIt);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */