class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>pref(2055);
        
        for (auto x: logs) {
            pref[x[0]]++;
            pref[x[1]]--;
        }
        for (int i = 1; i < 2055; i++)
            pref[i] += pref[i - 1];
        
        int year = 0, cnt = 0;
        for (int i = 1950; i <= 2050; i++) {
            if (pref[i] > cnt) {
                cnt = pref[i];
                year = i;
            }
        }
        return year;
    }
};