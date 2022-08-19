class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size(); 
        int ansl = -1, ansr = -1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] >= target)
                hi = mid;
            else
                lo = mid + 1;
        }
        ansl = lo;
        lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target)
                hi = mid;
            else
                lo = mid + 1;
        }
        ansr = lo - 1;
        if (ansl > ansr) return {-1, -1};
        return {ansl, ansr};
    }
};