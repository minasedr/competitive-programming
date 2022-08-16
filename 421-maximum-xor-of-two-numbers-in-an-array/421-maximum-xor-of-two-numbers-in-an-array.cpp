class Trie {
    struct TrieNode {
        int num;
        TrieNode *child[2];
    };
    public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    
    void insert(int n) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; i--) {
            bool bit = n & (1 << i);
            if (cur->child[bit] != NULL) {
                cur = cur->child[bit];
            } else {
                TrieNode* newNode = new TrieNode();
                cur->child[bit] = newNode;
                cur = newNode;
            }
        }
        cur->num = n;
    }
    
    int search(int n) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; i--) {
            bool bit = n & (1 << i);
            if (cur->child[not bit])
                cur = cur->child[not bit];
            else {
                cur = cur->child[bit];
            }
        }
        return cur->num;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* root = new Trie();
        int ans = 0;
        for (auto n : nums)
            root->insert(n);
        for (auto n : nums)
            ans = max(ans, n ^ root->search(n));
        
        return ans;
    }
};