class Solution {
public:
    bool ispal(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
    string breakPalindrome(string palindrome) {
        if (palindrome.size() == 1)
            return "";
        bool ok = true;
        for (auto &n : palindrome) {
            if (n > 'a') {
                char c = n;
                n = 'a';
                if (!ispal(palindrome)) {
                    ok = false;
                    break;
                }
                n = c;
            }
        }
        if (ok)
            palindrome.back() = 'b';
        return palindrome;
    }
};