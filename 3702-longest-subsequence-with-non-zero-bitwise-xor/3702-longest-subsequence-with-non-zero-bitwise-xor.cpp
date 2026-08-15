class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        int n = nums.size();
        //int left = 0;
        //int maxlength = 0;
        int totalxor = 0;

        for(int right = 0; right < n; right++){
            totalxor = totalxor ^ nums[right];
        }    
            if(totalxor != 0){
                return n;
            }
        for(int i =0; i<n; i++){
            if(nums[i] != 0){
                return n-1;
            }
        }
        return 0;
    }
};