class Solution {
public:
    int maxSum(vector<int>& nums, int k) {

        int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> ans(k, 0);

        for(int bit = 0; bit < 30; bit++) {
            int count = 0;

            for(int i = 0; i < n; i++) {
                if(nums[i] & (1 << bit)) {
                    count++;
                }
            }

            for(int i = 0; i < min(k, count); i++) {
                ans[i] |= (1 << bit);
            }
        }

        long long sum = 0;

        for(int i = 0; i < k; i++) {
            sum = (sum + 1LL * ans[i] * ans[i]) % MOD;
        }

        return sum;
    }
};