class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size(), ans = 0;
        map<int,int> cnt;
        
        for (auto d: tasks)
            cnt[d]++;
        
        for (auto [k, v]: cnt) {
            if (v == 1) return -1;
            ans += (v / 3 + ((v % 3) > 0));
        }
        return ans;
    }
};