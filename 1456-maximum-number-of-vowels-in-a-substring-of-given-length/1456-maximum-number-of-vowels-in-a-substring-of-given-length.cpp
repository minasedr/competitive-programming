class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char>vowels{'a','e','i','o','u'};
        multiset<char> st;
        int n = s.size();
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vowels.count(s[i]))
                st.insert(s[i]);
            if (i >= k and vowels.count(s[i - k]))
                st.erase(st.find(s[i - k]));
            ans = max(ans, (int)st.size());

        }
        return ans;
    }
};