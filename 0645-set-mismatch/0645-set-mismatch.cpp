class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        int miss = 0, sum = 0, m = nums.size();
        for (auto n: nums) {
            if (st.count(n)) {
                miss = n;
                continue;
            }
            st.insert(n);
            sum += n;
        }
        return {miss, (m + 1) * m / 2 - sum};
    }
};