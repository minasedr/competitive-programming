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
    vector<vector<int>> levelOrder(Node* root) {
        if (not root)
            return {};
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> res;
        while (!q.empty()) {
            int n = q.size();
            vector<int> cur;
            for (int i = 0; i < n; i++) {
                auto u = q.front();
                q.pop();
                for (auto v: u->children)
                    q.push(v);
                cur.push_back(u->val);
            }
            res.push_back(cur);
        }
        return res;
    }
};