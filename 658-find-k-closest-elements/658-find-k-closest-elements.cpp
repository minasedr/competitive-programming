class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            int diff = abs(arr[i] - x);
            pq.push({diff, i});
        }
        vector<int>ans;
        while (!pq.empty() && k--) {
            auto [dif, idx] = pq.top();
            pq.pop();
            ans.push_back(arr[idx]);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};