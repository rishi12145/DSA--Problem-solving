class Solution {
public:
    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        vector<int> suffix(n + 1, 0);

        
        for(int i = n - 1; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        return solve(0, 1, piles, dp, suffix);
    }

    int solve(int i, int m, vector<int>& piles,
              vector<vector<int>>& dp, vector<int>& suffix)
    {
        int n = piles.size();

        if(i >= n)
        {
            return 0;
        }

       
        if(dp[i][m] != -1)
        {
            return dp[i][m];
        }

        int best = 0;

        for(int x = 1; x <= 2 * m && i + x <= n; x++)
        {
            int nextM = max(m, x);

           
            int current = suffix[i] - solve(i + x, nextM, piles, dp, suffix);

            best = max(best, current);
        }

        dp[i][m] = best;

        return best;
    }
};