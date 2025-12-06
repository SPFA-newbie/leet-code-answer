#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<unordered_set>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    pair<int,int> DFS(Node* pos) {
        int max1 = 0, max2 = 0;
        int best = 0;
        for (auto child: pos->children) {
            pair<int,int> p = DFS(child);
            int dis = p.second;
            if (p.first > best) {
                best = p.first;
            }
            if (dis > max1) {
                max2 = max1;
                max1 = dis;
            } else if (dis > max2) {
                max2 = dis;
            }
        }
        if (max1 + max2 > best) {
            best = max1 + max2;
        }
        return make_pair(best, max1 + 1);
    }
    int diameter(Node* root) {
        return DFS(root).first;
    }
};