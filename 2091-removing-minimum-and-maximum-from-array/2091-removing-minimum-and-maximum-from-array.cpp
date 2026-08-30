class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        int max_count = INT_MIN;
        int min_count = INT_MAX;
        
        int min_index = -1;
        int max_index = -1;

        for(int i = 0; i <n; i++){
                if(nums[i] < min_count){
                    min_count = nums[i];
                    min_index = i;
                }

                if(nums[i] > max_count){
                    max_count = nums[i];
                    max_index = i;
            }
        }
        int left = max(max_index, min_index) + 1;
        int right = n - min(max_index, min_index);
        int both = min(min_index,max_index) + 1 + n - max(max_index, min_index);

        return min({left, right, both});
    }
};