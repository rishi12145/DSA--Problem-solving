class Solution {
public:
    int beautySum(string s) {
        
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            unordered_map<char,int> freq;

            for(int j = i ; j < n; j ++){
                freq[s[j]]++;

                int max_no = 0;
                int min_no = INT_MAX;
        
                for(auto check: freq){
                    max_no = max(max_no, check.second);
                    min_no = min(min_no, check.second);
                }
                ans = ans + (max_no - min_no);
            }
        }
           return ans;       
    }
};