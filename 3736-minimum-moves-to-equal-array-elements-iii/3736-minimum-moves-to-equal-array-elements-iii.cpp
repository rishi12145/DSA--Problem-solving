class Solution {
public:
    int minMoves(vector<int>& nums) {

         int n = nums.size();
         int largest;
         
         if(!nums.empty()){
            largest = *max_element(nums.begin(), nums.end());
         }

         int count = 0;

         for(int i = 0 ; i < n; i++){
            count = count + (largest - nums[i]);
         }

       return count;
    }
};