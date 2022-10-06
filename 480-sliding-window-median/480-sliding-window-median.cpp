using i64 = long long;
class Solution {
public:
    multiset<i64> mx, mn;
    void insert(i64 val) {
        mx.insert(val);
        if (mx.size() > mn.size() + 1) {
            mn.insert(*mx.rbegin());
            mx.erase(mx.find(*mx.rbegin()));
        }
        while (!mx.empty() && !mn.empty() && *mx.rbegin() > *mn.begin()) {
            int M = *mx.rbegin();
            int m = *mn.begin();
            mx.erase(mx.find(M));
            mn.erase(mn.find(m));
            mx.insert(m);
            mn.insert(M);
        }
    }
    
    double median() {
        int N = mx.size() + mn.size();
        double med = 0;
        if (N % 2 == 0)
            med = (*mx.rbegin() + *mn.begin()) / 2.0;
        else
            med = *mx.rbegin();
        return med;
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        
        for (int i = 0; i < k; i++)
            insert(nums[i]);
        
        for (int i = k; i < n; i++) {
            ans.push_back(median());
            if (mx.count(nums[i - k]))
                mx.erase(mx.find(nums[i - k]));
            else
                mn.erase(mn.find(nums[i - k]));
            insert(nums[i]);
        }
        ans.push_back(median());
        return ans;
    }
};