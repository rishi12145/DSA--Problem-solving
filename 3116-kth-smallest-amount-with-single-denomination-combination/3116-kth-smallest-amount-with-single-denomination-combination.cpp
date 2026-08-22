class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
   
        auto countLE = [&](long long x) -> long long {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = 0;
                bool overflow = false;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = __gcd(l, (long long)coins[i]);
                        long long newL = l / g * coins[i];
                       
                        if (newL > x) {
                            overflow = true;
                            break;
                        }
                        l = newL;
                        bits++;
                    }
                }
                if (overflow) continue;
                long long term = x / l;
                if (bits % 2 == 1) total += term;
                else total -= term;
            }
            return total;
        };
        
        int minCoin = *min_element(coins.begin(), coins.end());
        long long lo = 1, hi = (long long)minCoin * k;
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};