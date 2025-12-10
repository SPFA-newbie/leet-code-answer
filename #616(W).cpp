#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

struct WordTree {
    char c;
    bool end;
    WordTree* node[62];
    WordTree(char _c, bool _end) {
        c = _c;
        end = _end;
        for (int i = 0; i < 62; i++) {
            node[i] = nullptr;
        }
    }
    WordTree* next(char target) {
        if (target >= 'a' && target <= 'z') {
            return node[target - 'a'];
        }
        if (target >= 'A' && target <= 'Z') {
            return node[target - 'A' + 26];
        }
        if (target >= '0' && target <= '9') {
            return node[target - '0' + 52];
        }
        return nullptr;
    }
};

inline int getIndex(char target) {
    if (target >= 'a' && target <= 'z') {
        return target - 'a';
    }
    if (target >= 'A' && target <= 'Z') {
        return target - 'A' + 26;
    }
    if (target >= '0' && target <= '9') {
        return target - '0' + 52;
    }
    return -1;
}

class Solution {
public:
    WordTree* root;
    vector<pair<int, int>> bList;
    void addWord(string& word) {
        WordTree* pos = root;
        for (int i = 0; i < word.length(); i++) {
            if (pos->next(word[i]) == nullptr) {
                pos->node[getIndex(word[i])] = new WordTree(word[i], false);
            }
            pos = pos->next(word[i]);
        }
        pos->end = true;
    }
    void getBList(string& s) {
        WordTree* pos = root;
        int begin = -10;
        int end = -10;
        for (int i = 0; i < s.length(); i++) {
            if (pos->end) {
                end = i - 1;
            }
            if (pos->next(s[i]) == nullptr) {
                if (bList[bList.size()-1].second == begin - 1) {
                    bList[bList.size()-1].second = end;
                } else if (begin != -10 && end != -10) {
                    bList.push_back(make_pair(begin, end));
                }
                if (root->next(s[i]) != nullptr) {
                    pos = root->next(s[i]);
                    begin = i;
                    end = -10;
                } else {
                    pos = root;
                    begin = end = -10;
                }
            } else {
                if (pos == root) {
                    begin = i;
                }
                pos = pos->next(s[i]);
            }
        }
        if (pos->end) {
            end = s.length() - 1;
        }
        if (bList[bList.size()-1].second == begin - 1) {
            bList[bList.size()-1].second = end;
        } else if (begin != -10 && end != -10) {
            bList.push_back(make_pair(begin, end));
        }
    }
    void release(WordTree* node) {
        for (int i = 0; i < 62; i++) {
            if (node->node[i] != nullptr) {
                release(node->node[i]);
            }
        }
        delete node;
        return;
    }
    string addBoldTag(string s, vector<string>& words) {
        root = new WordTree(0, false);
        bList.clear();
        bList.push_back(make_pair(-100, -100));
        for (auto& word: words) {
            addWord(word);
        }
        getBList(s);
        string ans = "";
        int bpos = 1;
        for (int i = 0; i < s.length(); i++) {
            if (bList[bpos].first == i) {
                ans += "<b>";
            }
            ans.push_back(s[i]);
            if (bList[bpos].second == i) {
                ans += "</b>";
                bpos++;
            }
        }
        release(root);
        return ans;
    }
};