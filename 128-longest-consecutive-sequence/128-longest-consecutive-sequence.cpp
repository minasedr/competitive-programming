class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto x: nums)
            st.insert(x);
        int longest = 0, len = 0, cur = 0;
        for (auto x: st) {
            if (!st.count(x-1)) {
                cur = x;
                len = 1;
                while (st.count(++cur))
                    len++;
                longest = max(longest, len);
            }
        }
        return longest;
    }
};