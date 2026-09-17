class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();
        int ans = INT_MAX;
        int sum = 0;
        int left = 0;
        
        vector<int> best(n, INT_MAX);
        for(int i = 0; i < n; i++){
           sum = sum + arr[i];

           while(sum > target){
            sum = sum - arr[left];
            left++;
           }

           if(sum == target){
            int currentlen = i - left + 1;

              if(left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, currentlen + best[left - 1]);
                }

                if(i == 0){
                    best[i] = currentlen;
                }
                else{
                    best[i] = min(best[i-1], currentlen);
                }
           }
           else {
                if(i > 0)
                    best[i] = best[i - 1];
            }
        }

        if(ans == INT_MAX)
            return -1;

        return ans;
    }
};