class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        int n = nums.size();
        int ans = 0;
        vector<int> divisible;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++)
        {
            if(nums[i] % k == 0)
            {
                divisible.push_back(nums[i]);
            }
        }

        vector<int> multiple_of_k;

        for(int j = 1; j <= n + 1; j++)
        {
            multiple_of_k.push_back(k * j);
        }

        for(int j = 0; j < multiple_of_k.size(); j++)
        {
            bool found = false;

            for(int i = 0; i < divisible.size(); i++)
            {
                if(divisible[i] == multiple_of_k[j])
                {
                    found = true;
                    break;
                }
            }

            if(found == false)
            {
                ans = multiple_of_k[j];
                break;
            }
        }

        return ans;
    }
};