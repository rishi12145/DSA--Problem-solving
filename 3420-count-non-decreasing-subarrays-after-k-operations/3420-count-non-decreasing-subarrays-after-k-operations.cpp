class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        vector<int> nxt(n, -1);
        vector<int> st;

        // 1. Find next greater element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty())
                nxt[i] = st.back();

            st.push_back(i);
        }

        // 2. Binary lifting
        vector<vector<int>> up(LOG, vector<int>(n, -1));
        vector<vector<long long>> sum(LOG, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];

            if (nxt[i] != -1)
                sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        for (int p = 1; p < LOG; p++) {
            for (int i = 0; i < n; i++) {
                int mid = up[p - 1][i];

                if (mid != -1 && up[p - 1][mid] != -1) {
                    up[p][i] = up[p - 1][mid];

                    sum[p][i] = sum[p - 1][i] + sum[p - 1][mid];
                }
            }
        }

        // 3. Prefix sum
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // 4. Calculate required operations
        auto getCost = [&](int l, int r) -> long long {
            int cur = l;
            long long mxSum = 0;

            for (int p = LOG - 1; p >= 0; p--) {
                int j = up[p][cur];

                if (j != -1 && j <= r) {
                    mxSum += sum[p][cur];
                    cur = j;
                }
            }

            mxSum += 1LL * nums[cur] * (r - cur + 1);

            return mxSum - (pref[r + 1] - pref[l]);
        };

        // 5. Sliding window + Binary Search
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int lo = 0, hi = r;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (getCost(mid, r) <= k)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            ans += (r - lo + 1);
        }

        return ans;
    }
};
