#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>
using namespace std;

class Solution {
public:
    map<string, vector<string>> e;
    map<string, set<string>> from;
    vector<vector<string>> ans;
    void makeEdge(string& a, string& b) {
        int diff=0;
        for(int i=0;i<a.length();i++)
            if(a[i]!=b[i])
                diff++;

        if(diff==1) {
            e[a].push_back(b);
            e[b].push_back(a);
        }
    }
    void DFS(const string& pos, vector<string> now, string& beginWord) {
        if(pos==beginWord) {
            now.insert(now.begin(), pos);
            ans.push_back(now);
            now.erase(now.begin());
            return;
        }
        now.insert(now.begin(), pos);
        set<string>& use=from[pos];
        for(auto it=use.begin();it!=use.end();it++)
            DFS(*it, now, beginWord);
        now.erase(now.begin());
        return;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        e[beginWord]=vector<string>();
        for(int i=0;i<wordList.size();i++) {
            e[wordList[i]]=vector<string>();
            from[wordList[i]]=set<string>();
        }
        if(e.find(endWord)==e.end())
            return ans;
        for(int i=0;i<wordList.size();i++) {
            makeEdge(beginWord, wordList[i]);
            for(int j=i+1;j<wordList.size();j++)
                makeEdge(wordList[i], wordList[j]);
        }
            
        map<string, int> len;
        queue<string> q;
        len[beginWord]=1;
        q.push(beginWord);
        while(q.empty()==false) {
            string now=q.front();
            q.pop();
            vector<string> next=e[now];
            for(int i=0;i<next.size();i++) {
                if(len.find(next[i])==len.end()) {
                    len[next[i]]=len[now]+1;
                    from[next[i]].insert(now);
                    q.push(next[i]);
                }else if(len[next[i]]==len[now]+1) {
                    from[next[i]].insert(now);
                }
            }
        }
        vector<string> tp;
        DFS(endWord, tp, beginWord);
        return ans;
    }
};
