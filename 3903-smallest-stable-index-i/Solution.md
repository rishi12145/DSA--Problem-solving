# Smallest Stable Index I | Simple O(n²) Approach

# Intuition
For every index `i`, we need to find the maximum element from index `0` to `i` and the minimum element from index `i` to `n-1`.

If the difference between these two values is less than or equal to `k`, then `i` is a stable index.

We keep updating the maximum value as we move from left to right and use another loop to find the minimum value from the current index to the end.


# Approach
1. Initialize `max_no` as `INT_MIN`.
2. Traverse the array using index `i`.
3. Update `max_no` with the maximum value from `0` to `i`.
4. For every `i`, use another loop starting from `i` to find the minimum value.
5. Check if `max_no - min_no <= k`.
6. If the condition is true, store the index.
7. If no stable index is found, return `-1`.

# Complexity
- Time complexity: $O(n^2)$
- Space complexity: $O(1)$


# Code
```cpp []
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        
        int n = nums.size();
        int ans = INT_MAX;
        int max_no = INT_MIN;

        for(int i = 0 ; i <n; i++){
             max_no = max(max_no, nums[i]);
             int min_no = INT_MAX;

            for(int j = i; j <n; j++){
                min_no = min(min_no, nums[j]);
            }
                if(max_no - min_no <= k){
                    ans = min(ans, i);
                }   
        }        
                if(ans == INT_MAX)
                    return -1;
 
        return ans;
    }
};
```