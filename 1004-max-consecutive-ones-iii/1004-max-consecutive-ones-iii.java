class Solution {
    public int longestOnes(int[] nums, int k) {
        int n = nums.length;
        int[] pref = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1];
            if (nums[i - 1] == 0)
                pref[i]++;
        }
        
        int left = 0, ans = 0;
        int right = 0;
        while (right <= n) {
            while (pref[right] - pref[left] > k)
                left++;
            ans = Math.max(ans, right - left);
            right++;
        }
        return ans;
    }
}