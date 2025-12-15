#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    unordered_map<string, unordered_set<string>> wordMap;
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) {
            return false;
        }
        wordMap.clear();
        for (vector<string>& p: similarPairs) {
            auto it = wordMap.find(p[0]);
            if (it == wordMap.end()) {
                wordMap.insert(make_pair(p[0], unordered_set<string>()));
                it = wordMap.find(p[0]);
            }
            if (it->second.find(p[1]) == it->second.end()) {
                it->second.insert(p[1]);
            }
            it = wordMap.find(p[1]);
            if (it == wordMap.end()) {
                wordMap.insert(make_pair(p[1], unordered_set<string>()));
                it = wordMap.find(p[1]);
            }
            if (it->second.find(p[0]) == it->second.end()) {
                it->second.insert(p[0]);
            }
        }
        for (int i = 0; i < sentence1.size(); i++) {
            auto it = wordMap.find(sentence1[i]);
            if (sentence1[i] != sentence2[i] && (it == wordMap.end() || it->second.find(sentence2[i]) == it->second.end())) {
                return false;
            }
        }
        return true;
    }
};