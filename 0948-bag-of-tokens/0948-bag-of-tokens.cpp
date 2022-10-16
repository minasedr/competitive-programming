class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0, n = tokens.size();
        sort(tokens.begin(), tokens.end());
        
        int start = 0, end = n - 1, score = 0;
        if (start == end)
            return power >= tokens[start];
        
        while (start < end) {
            while (start <= end and power >= tokens[start]) {
                score++;
                power -= tokens[start];
                start++;
            }
            ans = max(ans, score);
            if (power < tokens[start] && score > 0) {
                score--;
                power += tokens[end];
                end--;
            } else
                start++;
        }
        return ans;
    }
};