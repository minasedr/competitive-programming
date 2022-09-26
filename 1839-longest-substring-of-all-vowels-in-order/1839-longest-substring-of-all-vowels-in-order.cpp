class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int start = 0, ans = 0, n = word.size();
        map<char, int> mp{{word[0], 1}};
        int form = 1, end = 1;
        
        while (end < n) {
            while (end < n && word[end] >= word[end - 1]) {
                if (mp[word[end]] == 0)
                    form++;
                mp[word[end]]++;
                end++;
            }
            if (form == 5)
                ans = max(ans, end - start);
            start = end;
            mp.clear();
            mp[word[end]]++;
            form = 1;
            end++;
        }
        return ans;
    }
};