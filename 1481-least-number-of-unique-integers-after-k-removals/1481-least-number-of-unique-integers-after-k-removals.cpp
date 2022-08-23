class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        map<int, int> m;
        for (auto x: arr)
            m[x]++;
        sort(arr.begin(), arr.end(), [&](int a, int b) {
            return m[a] < m[b];
        });
        int tmp = k;
        for (auto x: arr) {
            while (m[x] > 0 && tmp > 0) {
                m[x]--;
                tmp--;
            }
            if (tmp <= 0) break;
        }
        int ans = 0;
        for (auto [k, v]: m)
            ans += (v > 0);
        
        return ans;
    }
};