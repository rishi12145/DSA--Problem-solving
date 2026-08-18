class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n  = nums.size();

        vector<int> new_arr = nums;
        sort(new_arr.begin(), new_arr.end());
        int largest1 = new_arr[n-1];
        int largest2 = new_arr[n-2];   

             int product = (largest1 -1)*(largest2 -1);
           
        return product;
    }
};