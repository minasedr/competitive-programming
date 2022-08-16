struct Trie {
    struct TrieNode {
        bool isEnd = false;
        map<char, TrieNode*> child;
    };
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    
    void insert(string word) {
        TrieNode* cur = root;
        for (auto w: word) {
            if (cur->child[w])
                cur = cur->child[w];
            else {
                TrieNode* newNode = new TrieNode();
                cur->child[w] = newNode;
                cur = newNode;
            }
        }
        cur->isEnd = true;
    }
    string match(string word) {
        TrieNode* cur = root;
        string ans = "";
        for (auto w: word) {
            if (cur->isEnd)
                return ans;
            if (!cur->child[w])
                return "";
            cur = cur->child[w];
            ans += w;
        }
        return word;
    }
};
class Solution {
public:
    vector<string> split(string s) {
        string cur = "";
        vector<string>ans;
        for (auto x: s) {
            if (x == ' ') {
                ans.push_back(cur);
                cur = "";
            } else {
                cur += x;
            }
        }
        ans.push_back(cur);
        return ans;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* root = new Trie();
        for (auto s: dictionary) {
            root->insert(s);
        }
        vector<string> res = split(sentence);
        string ans = "";
        for (auto r: res) {
            string cur = root->match(r);
            ans += (cur == "" ? r : cur) + " ";
        }
        return ans.substr(0, ans.size() - 1);
    }
};