class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + stones[i - 1];
        }
        
        vector<long long> dp(n + 1, 0);
        dp[n] = 0;
        long long M = prefix[n] - dp[n]; // val[n]
        
        for (int i = n - 1; i >= 1; i--) {
            dp[i] = M;
            long long val_i = prefix[i] - dp[i];
            M = max(M, val_i);
        }
        
        return (int)dp[1];
    }
};