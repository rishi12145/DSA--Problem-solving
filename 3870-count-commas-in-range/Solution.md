# Count Commas — Bro, It’s Literally n - 999 💀

# Intuition

I opened this problem expecting LeetCode to test my DSA skills.

LeetCode opened the problem and said:

**"Bro, just check if n > 999."** 💀

If yes → `n - 999`  
If no → `0`

At this point, the hardest part of the problem was not the algorithm...

**It was believing that this was actually the POTD.** 🗿

# Approach

Numbers from `1` to `999` have no commas.

Starting from `1000`, every number has exactly one comma.

Therefore, if `n > 999`, the number of comma-containing numbers is simply:

`n - 999`

Otherwise, the answer is `0`.

# Complexity

- Time complexity: `O(1)` 🚀
- Space complexity: `O(1)` 🗿
- Brain complexity: `O(0)` 🗿🗿

# Code
```cpp []
class Solution {
public:
    int countCommas(int n) {

        
            if(n > 999){
                return n-999;
            }
            else{
                return 0;
            }
        
        return -1;
    }
};
```