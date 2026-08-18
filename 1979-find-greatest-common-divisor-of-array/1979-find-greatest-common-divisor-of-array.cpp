class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n  = nums.size();
        sort(nums.begin(), nums.end());

        int largest = nums[n-1];
        int smallest = nums[0];

        int max_divisor = 1;
        for(int i = 1; i <= smallest; i++){
            if(largest % i == 0 && smallest % i == 0){
                max_divisor = max(max_divisor, i);
            }
        }
        return max_divisor;
    }
};