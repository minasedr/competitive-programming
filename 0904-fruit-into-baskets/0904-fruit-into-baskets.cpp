class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int start = 0, ans = 0;
        map<int, int> cnt;
        for (int end = 0; end < n; end++) {
            cnt[fruits[end]]++;
            while (cnt.size() > 2) {
                if (--cnt[fruits[start]] == 0)
                    cnt.erase(fruits[start]);
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};