class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size(), beg = 0, ans = 0;
        
        for (int end = n - 1; end >= beg; end--) {
            if (people[beg] + people[end] <= limit)
                beg++;
            ans++;
        }
        return ans;
    }
};