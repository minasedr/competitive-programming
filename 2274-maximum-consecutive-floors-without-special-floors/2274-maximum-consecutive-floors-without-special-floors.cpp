class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans = 0;
        sort(special.begin(), special.end());
        ans = max(special[0] - bottom, ans);
        
        for (int i = 1; i < (int)special.size(); i++)
            ans = max(special[i] - special[i-1] - 1, ans);
        
        ans = max(top - special.back(), ans);
        return ans;
    }
};