using i64 = long long;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<i64> pref(n + 1);
        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + nums[i - 1];
        
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            while (!q.empty() && pref[q.back()] >= pref[i])
                q.pop_back();
            
            while (!q.empty() && pref[i] - pref[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            
            q.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};