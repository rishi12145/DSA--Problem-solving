class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        int n = nums.size();
        int ans = INT_MAX;
        int sum = 0;

        for(int i = 0; i <n; i++){

            int num = nums[i];
            int sum = 0;
            
            sum = sum + num % 10;
            num = num / 10;

        while(num > 0){
            sum = sum + num % 10;
            num = num / 10;
        }
            if(sum == i){
                
                return i;
            }
        }   
        return -1;   
    }
};