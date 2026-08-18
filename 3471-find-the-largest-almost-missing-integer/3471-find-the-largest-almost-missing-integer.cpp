class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> freq;

        for(int i = 0; i <= n - k; i++)
        {
            for(int j = i; j < i + k; j++)
            {
                bool found = false;

                for(int x = i; x < j; x++)
                {
                    if(nums[x] == nums[j])
                    {
                        found = true;
                        break;
                    }
                }

                if(found == false)
                {
                    freq[nums[j]]++;
                }
            }
        }

        int ans = -1;

        for(auto x : freq)
        {
            if(x.second == 1)
            {
                ans = max(ans, x.first);
            }
        }

        return ans;
    }
};