class Solution {
public:
    int power(int n) {
        if (n == 1)
            return 0;
        if (n % 2 == 0)
            return 1 + power(n / 2);
        return 1 + power(3 * n + 1);
    }
    int getKth(int lo, int hi, int k) {
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
        for (int i = lo; i <= hi; i++)
            pq.push({power(i), i});
        
        int ans = -1;
        while(k--) {
            ans = pq.top()[1];
            pq.pop();
        }
        return ans;
    }
};