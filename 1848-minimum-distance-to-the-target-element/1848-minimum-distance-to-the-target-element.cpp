class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        
        int n = nums.size();
        int distance = INT_MAX;
    
        for(int i = 0; i <n; i++){
            if(nums[i] == target){
                distance = min(distance, abs(i - start));
            }    
        }
        return distance;
    }
};