class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int n  = nums.size();
        vector<int> new_arr;

        for(int i = 0; i <n; i++){
            if(nums[i] == val)
            continue;
            new_arr.push_back(nums[i]);
        }

        for(int i = 0; i< new_arr.size(); i++){
            nums[i] = new_arr[i];
        }

        return new_arr.size();
        
    }
};