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
    Node* findRoot(vector<Node*> tree) {
        unordered_set<long long> arr;
        for (int i = 0; i < tree.size(); i++) {
            arr.insert((long long)tree[i]);
        }
        for (int i = 0; i < tree.size(); i++) {
            for (int j = 0; j < tree[i]->children.size(); j++)
            arr.erase((long long)tree[i]->children[j]);
        }
        return (Node*) (*arr.begin());
    }
};