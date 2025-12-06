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
    Node* copyNode(Node* tar) {
        if (tar == NULL) return NULL;
        Node* now = new Node(tar->val);
        now->children = vector<Node*>();
        for (auto child: tar->children) {
            now->children.push_back(copyNode(child));
        }
        return now;
    }
    Node* cloneTree(Node* root) {
        return copyNode(root);
    }
};