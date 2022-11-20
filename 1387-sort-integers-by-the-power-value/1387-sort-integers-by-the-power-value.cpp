vector<int> dp(1000000, -1);

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq; 
        dp[1] = 0;

        function<int(int)> power;
        power = [&](int n) {
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
