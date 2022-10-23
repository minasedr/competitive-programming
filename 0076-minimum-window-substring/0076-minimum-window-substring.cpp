class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), beg = 0, end = 0;
        unordered_map<char, int> window, T;
        
        for (auto x: t)
            T[x]++;
        int req = T.size(), form = 0;
        int ans[3] = {INT_MAX, 0, 0};
        
        while (end < n) {
            char chr = s[end];
            window[chr]++;
            if (T.count(chr) && T[chr] == window[chr])
                form++;
            while (beg <= end && form == req) {
                chr = s[beg];
                if (end - beg + 1 < ans[0]) {
                    ans[0] = end - beg + 1;
                    ans[1] = beg;
                    ans[2] = end;
                }
                window[chr]--;
                if (T.count(chr) && window[chr] < T[chr])
                    form--;
                beg++;
            }
            end++;
        }
        return (ans[0] == INT_MAX ? "" : s.substr(ans[1], ans[0]));
    }
};