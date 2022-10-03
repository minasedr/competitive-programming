/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (not root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            Node* node;
            for (int i = 0; i < n; i++) {
                node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                if (!q.empty())
                    node->next = q.front();
            }
            node->next = NULL;
        }
        return root;
    }
};