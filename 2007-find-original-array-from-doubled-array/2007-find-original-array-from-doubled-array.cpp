class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        map<int, int> cnt;
        sort(changed.begin(), changed.end());
        vector<int> ans;
        
        for(auto s:changed)
            cnt[s]++;
        
        for (auto s: changed) {
            if (cnt[s]-- > 0) {
                if (cnt[2 * s]-- > 0)
                    ans.push_back(s);
                else
                    return {};
            }
        }
        
        return ans;
    }
};