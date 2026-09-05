# Smallest Stable Index II (u can say Smallest Stable Index I) | --> O(n) Optimized Approach

# Intuition

I had solved the previous version of this problem using the same basic approach.

For every index `i`, we need the maximum value from `0` to `i` and the minimum value from `i` to `n-1`.

In the previous version, I used another loop to find the minimum for every index, which took `O(n²)` time.

Here, I can improve the time complexity by storing the minimum value from every index to the end in an array.

# Approach

1. Create a `min_right` array to store the minimum value from index `i` to `n-1`.
2. Fill this array from right to left.
3. Traverse the array from left to right.
4. Keep updating `max_no` with the maximum value from `0` to `i`.
5. Check if `max_no - min_right[i] <= k`.
6. Return the first index that satisfies the condition.
7. If no stable index is found, return `-1`.

# Complexity

- Time complexity: $O(n)$

- Space complexity: $O(n)$

# Code
```cpp []
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
```