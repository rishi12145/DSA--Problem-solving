class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n = nums.size();

        int minimum = *min_element(nums.begin(), nums.end());

        int count = 0;

        for(int i = 0 ; i < n; i++){
            count = count + (nums[i] - minimum);
        }
        return count;
        
    }
};