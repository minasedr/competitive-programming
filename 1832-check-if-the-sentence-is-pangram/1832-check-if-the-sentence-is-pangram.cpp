class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>vis(sentence.begin(), sentence.end());
        return vis.size() == 26;
    }
};