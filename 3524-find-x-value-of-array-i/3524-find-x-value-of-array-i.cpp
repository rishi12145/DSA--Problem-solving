class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for(int num : nums) {

            int val = num % k;

            vector<long long> newDp(k, 0);

        
            newDp[val]++;

        
            for(int r = 0; r < k; r++) {

                if(dp[r] == 0)
                    continue;

                int newR = (r * val) % k;

                newDp[newR] += dp[r];
            }

          
            for(int r = 0; r < k; r++) {
                result[r] += newDp[r];
            }

            dp = newDp;
        }

        return result;
    }
};