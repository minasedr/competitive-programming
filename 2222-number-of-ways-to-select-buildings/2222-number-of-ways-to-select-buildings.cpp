class Solution {
public:
    long long numberOfWays(string s) {
        int len = s.size();
        long long answer = 0;
        int suff_one = count(s.begin(), s.end(), '1');
        int suff_zero = len - suff_one;
        
        int cnt_one = 0, cnt_zero = 0;
        for (int i = 0; i < len; i++) {
            suff_one -= (s[i] == '1');
            suff_zero -= (s[i] == '0');
            if (s[i] == '0')
                answer += (cnt_one * suff_one);
            else
                answer += (cnt_zero * suff_zero);
            cnt_one += (s[i] == '1');
            cnt_zero += (s[i] == '0');
        }
        
        return answer;
    }
};