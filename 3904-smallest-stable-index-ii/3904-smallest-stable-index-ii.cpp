class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = INT_MAX;
        int max_no = INT_MIN;

        vector<int> min_right(n);
        min_right[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--) {
            min_right[i] = min(min_right[i + 1], nums[i]);
        }

        for(int i = 0; i < n; i++) {
            max_no = max(max_no, nums[i]);

            if(max_no - min_right[i] <= k) {
                ans = min(ans, i);
            }
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};