class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, remain = 0, cur = 0;
        for (int i = 0; i < gas.size(); i++) {
            cur += gas[i] - cost[i];
            if (cur < 0) {
                ans = i + 1;
                remain += cur;
                cur = 0;
            }
        }
        return cur + remain >= 0 ? ans : -1;
    }
};