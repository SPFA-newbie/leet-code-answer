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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    TreeNode* createTreeNode(Node* node, vector<Node*>& bro, int pos) {
        TreeNode* treeNode = new TreeNode(node->val);
        if (node->children.size() != 0) {
            treeNode->left = createTreeNode(node->children[0], node->children, 1);
        }
        if (pos != bro.size()) {
            treeNode->right = createTreeNode(bro[pos], bro, pos + 1);
        }
        return treeNode;
    }
    Node* createNode(TreeNode* node, vector<Node*>& children) {
        Node* now = new Node(node->val);
        children.push_back(now);
        if (node->left != nullptr) {
            createNode(node->left, now->children);
        }
        if (node->right != nullptr) {
            createNode(node->right, children);
        }
        return now;
    }
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<Node*> rootBro;
        return createTreeNode(root, rootBro, 0);
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<Node*> rootBro;
        return createNode(root, rootBro);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));