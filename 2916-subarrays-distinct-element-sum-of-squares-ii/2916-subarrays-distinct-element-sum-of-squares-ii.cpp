class Solution {
public:
    using ll = long long;
    const int MOD = 1e9 + 7;

    vector<ll> sum, sq, lazy;

    void apply(int node, int l, int r, ll v) {
        ll len = r - l + 1;

        sq[node] = (sq[node] + 2 * v * sum[node]
                    + len * v % MOD * v) % MOD;

        sum[node] = (sum[node] + len * v) % MOD;
        lazy[node] = (lazy[node] + v) % MOD;
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0 || l == r) return;

        int mid = (l + r) / 2;
        apply(node * 2, l, mid, lazy[node]);
        apply(node * 2 + 1, mid + 1, r, lazy[node]);

        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);
        int mid = (l + r) / 2;

        if (ql <= mid)
            update(node * 2, l, mid, ql, qr);

        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        vector<int> last(100001, -1);
        ll ans = 0;

        for (int j = 0; j < n; j++) {
            int prev = last[nums[j]];

            update(1, 0, n - 1, prev + 1, j);

            last[nums[j]] = j;
            ans = (ans + sq[1]) % MOD;
        }

        return ans;
    }
};