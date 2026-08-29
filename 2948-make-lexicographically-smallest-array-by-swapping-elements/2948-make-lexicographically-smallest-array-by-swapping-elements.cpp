class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++)
        {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int i = 0;

        while(i < n)
        {
            int j = i;

            while(j + 1 < n && arr[j + 1].first - arr[j].first <= limit)
            {
                j++;
            }

            vector<int> values;
            vector<int> indexes;

            for(int k = i; k <= j; k++)
            {
                values.push_back(arr[k].first);
                indexes.push_back(arr[k].second);
            }

            sort(indexes.begin(), indexes.end());

            for(int k = 0; k < values.size(); k++)
            {
                nums[indexes[k]] = values[k];
            }

            i = j + 1;
        }

        return nums;
    }
};