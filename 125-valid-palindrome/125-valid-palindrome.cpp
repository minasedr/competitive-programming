class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        vector<char> v;
        for (int i = 0; i <n ;i++) {
            if (isalnum(s[i]) and s[i] != ' ')
                v.push_back(s[i]);
        }
        n = v.size();
        for (int i = 0; i < v.size(); i++)
            if ( tolower(v[i]) != tolower(v[n-i-1]))
                return false;
        return true;
    }
};