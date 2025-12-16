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

string& operator+(string& target, int x) {
    char* xp = reinterpret_cast<char*>(&x);
    for (int i = 0; i < 4; i++) {
        target.push_back(xp[i]);
    }
    return target;
}

int getVal(string& s, int pos) {
    char val[4] = {0};
    for (int i = 0; i < 4; i++) {
        val[i] = s[pos+i];
    }
    return *(reinterpret_cast<int*>(val));
}

class Codec {
public:
    void createString(Node* node, string& s) {
        s = s + node->val;
        s = s + static_cast<int>(node->children.size());
        for (auto& child: node->children) {
            createString(child, s);
        }
    }

    void createNode(Node* node, string& s, int& pos) {
        node->val = getVal(s, pos);
        pos += 4;
        int childrenNum = getVal(s, pos);
        pos += 4;
        for (int i = 0; i < childrenNum; i++) {
            Node* child = new Node();
            node->children.push_back(child);
            createNode(child, s, pos);
        }
    }
    
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (root == nullptr) {
            return "";
        }
        string ret = "";
        createString(root, ret);
        return ret;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.length() == 0) {
            return nullptr;
        }
        Node* root = new Node();
        int pos = 0;
        createNode(root, data, pos);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));