#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;

class Solution {
public:
    map<string, vector<string>> e;
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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        e[beginWord]=vector<string>();
        for(int i=0;i<wordList.size();i++)
            e[wordList[i]]=vector<string>();
        if(e.find(endWord)==e.end())
            return 0;
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
                if(next[i]==endWord)
                    return len[now]+1;
                if(len.find(next[i])==len.end()) {
                    len[next[i]]=len[now]+1;
                    q.push(next[i]);
                }
            }
        }
        return len[endWord];
    }
};
