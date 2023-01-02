class Solution {
public:
    bool detectCapitalUse(string word) {
        bool small = false, cap = false;
        int n = word.size();
        for (char c: word) {
            if (islower(c))
                small = true;
            if (isupper(c))
                cap = true;
        }
        if (small and cap) {
            for (int i = 1; i < n; i++)
                if (isupper(word[i]))
                    return false;
        }
        return true;
    }
};