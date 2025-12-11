#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

class Solution {
public:
    int getIndex(char c, vector<pair<char, int>>& end) {
        for (int i = 0; i < end.size(); i++) {
            if (end[i].first == c) {
                return i;
            }
        }
        return -1;
    }
    int getEarliestIndex(vector<pair<char, int>>& end) {
        int earlistIndex = 0;
        for (int i = 1; i < end.size(); i++) {
            if (end[i].second < end[earlistIndex].second) {
                earlistIndex = i;
            }
        }
        return earlistIndex;
    }
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) {
            return 0;
        }
        vector<pair<char, int>> end;
        end.push_back(make_pair(s[0], 0));
        for (int i = 1; i < k; i++) {
            end.push_back(make_pair(0, -1));
        }
        int best = 0;
        int start = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) {
                end[getIndex(s[i], end)].second = i;
            } else {
                int index = getIndex(s[i], end);
                if (index == -1) {
                    best = max(best, i - start);
                    int earlistIndex = getEarliestIndex(end);
                    start = end[earlistIndex].second + 1;
                    end[earlistIndex].first = s[i];
                    end[earlistIndex].second = i;
                } else {
                    end[index].second = i;
                }
            }
        }
        return max(best, (int)s.length() - start);
    }
};