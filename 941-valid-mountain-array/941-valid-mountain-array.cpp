class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int idx = 0, n = arr.size();
        
        while (idx + 1 < n && arr[idx] < arr[idx + 1])
            idx++;
        if (idx == 0 || idx == n - 1) return false;
        while (idx + 1 < n && arr[idx] > arr[idx + 1])
            idx++;
        return idx == n - 1;
    }
};