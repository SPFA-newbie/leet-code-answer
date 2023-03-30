/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<int, Node*> nlist;
    Node* make(Node* node) {
        if(node==nullptr)return nullptr;
        if(nlist.find(node->val)!=nlist.end())
            return nlist[node->val];
        
        Node* nd=new Node(node->val);
        nlist[node->val]=nd;
        for(int i=0;i<node->neighbors.size();i++) {
            Node* c=make(node->neighbors[i]);
            if(c!=nullptr)
                nd->neighbors.push_back(c);
        }
        return nd;
    }
    Node* cloneGraph(Node* node) {
        return make(node);
    }
};
