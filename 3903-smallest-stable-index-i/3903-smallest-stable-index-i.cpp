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