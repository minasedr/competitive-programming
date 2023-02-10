class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = target.size(), ans = 0;
        map<string, int> cnt;
        
        for (auto num: nums)
            cnt[num]++;
        
        for (auto [k, v] : cnt) {
            if (target.find(k) == 0) {
                string suff = target.substr(k.size(), n);
                ans += v * cnt[suff];
                if (k == suff)
                    ans -= cnt[suff];
            }
        }
        
        return ans;
    }
};