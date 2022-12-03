class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> cur;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                cur.push_back(0);
                cur.push_back(0);
            } else
                cur.push_back(arr[i]);
        }
        vector<int> ans(cur.begin(), cur.begin() + n);
        arr = ans;
    }
};