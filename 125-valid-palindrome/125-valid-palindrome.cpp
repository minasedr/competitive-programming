class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int beg = 0, end = n - 1;
        while (beg < end) {
            while (beg < end and not isalnum(s[beg]))
                beg++;
            while (beg < end and not isalnum(s[end]))
                end--;
            while (beg < end and tolower(s[beg]) != tolower(s[end]))
                return false;
            beg++, end--;
        }
        return true;
    }
};