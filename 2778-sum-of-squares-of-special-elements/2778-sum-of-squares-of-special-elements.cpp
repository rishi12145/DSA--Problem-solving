class Solution {
public:
    int sumOfSquares(vector<int>& nums) {

        int n = nums.size();
        vector<int> temp;
        int sqre = 0;

        for(int i = 0; i < n; i++){
            
            if(n % (i + 1) == 0){
                temp.push_back(nums[i]);
            }
        }

        int m = temp.size();
        for(int j = 0; j < m; j++){
            sqre = sqre + temp[j]*temp[j];
        }
        return sqre;     
    }
};