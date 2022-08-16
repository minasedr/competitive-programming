class Trie {
    struct TrieNode {
        bool isEnd;
        unordered_map<char, TrieNode*> children;
    };
    
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* cur = root;
        for (auto ch: word) {
            if (cur->children.count(ch))
                cur = cur->children[ch];
            else {
                TrieNode* newNode = new TrieNode();
                cur->children[ch] = newNode;
                cur = newNode;
            }
        }
        cur->isEnd = true;
    }

    bool search(string word) {
       TrieNode* cur = root;
        for (auto ch: word) {
            if (!cur->children.count(ch))
                return false;
            cur = cur->children[ch];
        }
        return cur->isEnd;
    }

    bool startsWith(string prefix) {
       TrieNode* cur = root;
        for (auto ch: prefix) {
            if (!cur->children.count(ch))
                return false;
            cur = cur->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
