class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = target.size();
        unordered_map<string, int> cnt;
        
        for (auto num: nums)
            cnt[num]++;
        
        int ans = 0;
        for (auto [num, k] : cnt) {
            if (target.find(num) == 0) {
                string s = target.substr(num.size(), n);
                ans += (k * cnt[s]);
                if (s == num) 
                    ans -= cnt[s];    
            }
        }
        
        return ans;
    }
};