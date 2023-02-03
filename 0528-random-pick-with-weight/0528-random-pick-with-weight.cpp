class Solution {
public:
    vector<int> pref;
    Solution(vector<int>& w) {
        pref = w;
        int n = pref.size();
        for (int i = 1; i < n; i++)
            pref[i] += pref[i - 1];
    }
    
    int pickIndex() {
        int idx = rand() % pref.back();
        return upper_bound(pref.begin(), pref.end(), idx) - pref.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */