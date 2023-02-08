class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> pref(n, n - 1);
        
        for (int i = n - 2; i >= 0; i--)
            pref[i] = (s[i] <= s[pref[i + 1]] ? pref[i + 1] : i);
        
        for (int i = 0; i < n - 1; i++) {
            if (s[i] < s[pref[i + 1]]) {
                swap(s[i], s[pref[i + 1]]);
                break;
            }
        }
        return stoi(s);
    }
};