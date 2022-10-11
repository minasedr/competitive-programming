class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        q.push(start);
        set<int> vis;
        vis.insert(start);
        function<bool(int)> inbound = [&](int x) {
            return (x >= 0 && x < arr.size());
        };
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (arr[i] == 0)
                return true;
            if (!vis.count(i + arr[i]) && inbound(i + arr[i])) {
                vis.insert(i + arr[i]);
                q.push(i + arr[i]);
            }
            if (!vis.count(i - arr[i]) && inbound(i - arr[i])) {
                vis.insert(i - arr[i]);
                q.push(i - arr[i]);
            }
        }
        return false;
    }
};