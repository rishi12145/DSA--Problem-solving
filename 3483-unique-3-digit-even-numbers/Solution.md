# Total Numbers With Even Last Digit --> (n^3)

# Intuition

We need to make all possible 3-digit numbers using three different digits from the given array.

The first digit cannot be `0` because then it would not be a 3-digit number.

The last digit must be even, so after creating the number, I check whether it is divisible by `2`.

I use a `set` to store the numbers so that duplicate numbers are counted only once.

# Approach

1. Use three loops to choose the hundreds, tens, and units digits.
2. Make sure all three positions are different using their indices.
3. Skip the combination if the first digit is `0`.
4. Create the 3-digit number using:
   `100 * digits[i] + 10 * digits[j] + digits[k]`
5. Check if the number is even.
6. Store the valid number in a `set` so duplicate numbers are not counted.
7. Return the size of the set.

# Complexity

- Time complexity: $O(n^3)$
- Space complexity: $O(n^3)$

# Code
```cpp []
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int n = digits.size();
        set<int> ans;
        

        for(int i = 0; i <n; i++){
            for(int j = 0; j <n; j++){
                for(int k = 0; k <n; k++){

                    if(i != j && j != k && i != k){

                        if(digits[i] == 0)
                        continue;

                        int number = 100* digits[i] + 10*digits[j] + digits[k];
                    
                        if(number % 2 == 0){

                        ans.insert(number);
                        }
                    }
                }
            }
        }
        return ans.size();
    }
};
```