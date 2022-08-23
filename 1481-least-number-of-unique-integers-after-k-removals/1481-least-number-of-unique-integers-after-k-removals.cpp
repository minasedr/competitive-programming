class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> m;
        for (auto x: arr)
            m[x]++;
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return m[a] < m[b];
        });
        for (auto x: arr) {
            while (m[x] > 0 && k > 0) {
                m[x]--;
                k--;
            }
            if (k <= 0) break;
        }
        int ans = 0;
        for (auto [k, v]: m)
            ans += (v > 0);
        
        return ans;
    }
};