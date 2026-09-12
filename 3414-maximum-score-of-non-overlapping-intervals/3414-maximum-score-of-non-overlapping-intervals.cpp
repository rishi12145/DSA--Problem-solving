class Solution {
public:

    struct State {
        long long score;
        vector<int> indices;
    };

    bool better(const State& a, const State& b) {

        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        int n = intervals.size();

        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

       
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        vector<int> ends(n);

        for (int i = 0; i < n; i++) {
            ends[i] = intervals[i][1];
        }

     
        vector<vector<State>> dp(
            5,
            vector<State>(n + 1)
        );

        for (int k = 0; k <= 4; k++) {
            dp[k][0] = {0, {}};
        }

        for (int i = 1; i <= n; i++) {

            int cur = i - 1;

            int start = intervals[cur][0];
            int weight = intervals[cur][2];
            int originalIndex = intervals[cur][3];

            int pos = lower_bound(
                ends.begin(),
                ends.begin() + cur,
                start
            ) - ends.begin();

          
            int previous = pos;

            for (int k = 1; k <= 4; k++) {

          
                State skip = dp[k][i - 1];

               
                State take = dp[k - 1][previous];

                take.score += weight;

                
                take.indices.push_back(originalIndex);

                sort(
                    take.indices.begin(),
                    take.indices.end()
                );

                if (better(take, skip))
                    dp[k][i] = take;
                else
                    dp[k][i] = skip;
            }
        }

        return dp[4][n].indices;
    }
};