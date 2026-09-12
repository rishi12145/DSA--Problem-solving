class Solution {
public:
    
    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& used,      vector<vector<int>>& ans){

        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

         for(int i = 0 ; i < nums.size(); i++){
            
            if(used[i])
            continue;

            used[i] = true;
            temp.push_back(nums[i]);

             backtrack(nums, temp, used, ans);

            temp.pop_back();
            used[i] = false;
        }

    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> temp;
        vector<bool> used(n, false);
        vector<vector<int>> ans;

        backtrack(nums, temp, used, ans);

        return ans;
    }
};