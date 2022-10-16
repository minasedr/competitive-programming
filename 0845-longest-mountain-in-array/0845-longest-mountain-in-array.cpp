class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> pref(n);
        
        for (int i = 1; i < n; i++)
            if (arr[i] > arr[i - 1])
                pref[i] = pref[i - 1] + 1;
        
        int cur = 0, ans = 0;
        for (int i = n - 2; i > -1; i--) {
            cur = (arr[i] > arr[i + 1] ? cur + 1: 0);
            
            if (pref[i] > 0 and cur > 0)
                ans = max(ans, pref[i] + cur + 1);
        }
        return ans;
    }
};