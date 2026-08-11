class Solution {
public:
    int missingInteger(vector<int>& nums) {

        int n = nums.size();

        int sum = nums[0];

        // Find longest sequential prefix
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i - 1] + 1)
            {
                sum = sum + nums[i];
            }
            else
            {
                break;
            }
        }

        // Find smallest missing number >= sum
        while(true)
        {
            bool found = false;

            for(int i = 0; i < n; i++)
            {
                if(nums[i] == sum)
                {
                    found = true;
                    break;
                }
            }

            if(found == false)
            {
                return sum;
            }

            sum++;
        }
    }
};