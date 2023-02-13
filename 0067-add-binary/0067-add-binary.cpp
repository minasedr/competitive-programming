class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ans;
        
        while (i >= 0 or j >= 0) {
            int cur = carry;
            if (i >= 0) cur += (a[i] - '0');
            if (j >= 0) cur += (b[j] - '0');
            carry = (cur > 1 ? 1: 0);
            i--, j--;
            ans += char((cur % 2) + '0');
        }
        if (carry) ans += '1';
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};