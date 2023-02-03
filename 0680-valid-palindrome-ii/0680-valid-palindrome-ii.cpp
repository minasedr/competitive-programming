class Solution {
public:
    
    bool validPalindrome(string s) {
        int n = s.size();
        int beg = 0, end = n - 1;
        
        function<bool(int)> valid;
        valid = [&](int i) {
            string cur = s.substr(0, i) + s.substr(i + 1, n);
            string rev = cur;
            reverse(rev.begin(), rev.end());
            return (cur == rev);
        };
        while (beg < end) {
            if (s[beg] == s[end])
                beg++, end--;
            else
                break;
        }
        
        if (valid(beg) or valid(end))
            return true;
        return false;
            
    }
};