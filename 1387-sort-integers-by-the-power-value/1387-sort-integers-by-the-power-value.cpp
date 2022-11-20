class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> dp(1000000, -1);
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq; 
        
        function<int(int)> power;
        power = [&](int n) {
            if (n == 1) return 0;
            if (dp[n] != -1)
                return dp[n];
            int cnt = 1 + (n & 1 ? power(3 * n + 1) : power(n / 2));
            return dp[n] = cnt;
        };
        
        for(int i = lo; i <= hi; i++)
            pq.push({power(i), i});
        
        while(--k)
            pq.pop();
        
        return pq.top()[1];
    }
};
