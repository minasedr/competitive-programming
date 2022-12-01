/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        function<int(TreeNode*)> leftH;
        function<int(TreeNode*)> rightH;
        
        leftH = [](TreeNode* root) {
            int h = 0;
            while (root) {
                h++;
                root = root->left;
            }
            return h;
        };
        rightH = [](TreeNode* root) {
            int h = 0;
            while (root) {
                h++;
                root = root->right;
            }
            return h;
        };
        int left = leftH(root);
        int right = rightH(root);
        if (left == right)
            return (1 << left) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};