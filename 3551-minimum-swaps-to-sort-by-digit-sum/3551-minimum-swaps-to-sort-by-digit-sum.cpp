
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> temp;

        for (int i = 0; i < n; i++) {
            int m = nums[i];
            int sum = 0;

            while (m > 0) {
                int digit = m % 10;
                sum = sum + digit;
                m = m / 10;
            }

            temp.push_back({sum, nums[i]});
        }

        sort(temp.begin(), temp.end());

        vector<int> target;
        for (int i = 0; i < n; i++) {
            target.push_back(temp[i].second);
        }

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target[i]) {
                continue;
            }

            int j = pos[target[i]];

            pos[nums[i]] = j;
            pos[target[i]] = i;

            swap(nums[i], nums[j]);
            swaps++;
        }

        return swaps;
    }
};
