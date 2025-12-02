#include<vector>
using namespace std;

class Solution {
public:
    bool DFS(vector<vector<int>>& graph, vector<bool>& arr, vector<bool>& acc, int pos, int tar) {
        arr[pos] = true;
        bool hasNext = false;
        for (auto next: graph[pos]) {
            if (arr[next] == true) return false;
            hasNext = true;
            if (acc[next]) continue;
            if (DFS(graph, arr, acc, next, tar) == false) return false;
        }
        if (hasNext && pos == tar) return false;
        if (!hasNext && pos == tar) {
            arr[pos] = false;
            acc[pos] = true;
            return true;
        }
        if (hasNext) {
            arr[pos] = false;
            acc[pos] = true;
            return true;
        }
        return false;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph;
        vector<bool> arr;
        vector<bool> acc;
        for (int i = 0; i < n; i++) {
            graph.push_back(vector<int>());
            arr.push_back(false);
            acc.push_back(false);
        }
        for (auto e: edges) {
            graph[e[0]].push_back(e[1]);
        }
        return DFS(graph, arr, acc, source, destination);
    }
};