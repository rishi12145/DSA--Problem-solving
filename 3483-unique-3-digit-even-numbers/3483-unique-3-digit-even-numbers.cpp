class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        int n = digits.size();
        set<int> ans;
        

        for(int i = 0; i <n; i++){
            for(int j = 0; j <n; j++){
                for(int k = 0; k <n; k++){

                    if(i != j && j != k && i != k){

                        if(digits[i] == 0)
                        continue;

                        int number = 100* digits[i] + 10*digits[j] + digits[k];
                    
                        if(number % 2 == 0){

                        ans.insert(number);
                        }
                    }
                }
            }
        }
        return ans.size();
    }
};