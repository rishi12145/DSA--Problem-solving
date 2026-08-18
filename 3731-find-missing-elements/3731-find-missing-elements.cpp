class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int smallest = nums[0];
        int largest = nums[n-1];

        vector<int> ans;

        for(int i = smallest; i <= largest; i++){
            bool found = false;

           for(int j = 0; j < n; j++){
            if(nums[j] == i){
                found = true;
                break;
            }
           }
            if(!found){
                ans.push_back(i);
            }
        }
        return ans;
    }
};