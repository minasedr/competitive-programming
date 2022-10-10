class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        
        if (n == 1) return "";
        bool ok = false;
        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] != 'a') {
                palindrome[i] = 'a';
                ok = true;
                break;
            }
        }
        
        if (!ok)
            palindrome.back() = 'b';
        return palindrome;
    }
};