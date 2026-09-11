class Solution {
public:
    int romanToInt(string s) {
        
        int n = s.size();
        int ans = 0;

    for(int i = 0 ; i <n; i++){
        
        if(s[i] == 'I'){
            if(i+1 < n && (s[i+1] == 'V' || s[i+1] == 'X')){
                ans = ans-1;
            }
                else{
                ans = ans + 1;
                }
        }

        if(s[i] == 'V'){
            ans = ans + 5;
        }

        if(s[i] == 'X'){

            if(i+1 < n && (s[i+1] == 'L' || s[i+1] == 'C')){
                ans = ans-10;
            }
                else{
                ans = ans + 10;
                }
        }

        if(s[i] == 'L'){
            ans = ans + 50;
        }
        
        if(s[i] == 'C'){

            if(i+1 < n && (s[i+1] == 'D' || s[i+1] == 'M')){
                ans = ans-100;
            }
                else{
                ans = ans + 100;
                }
        }


        if(s[i] == 'D'){
            ans = ans + 500;
        }

        if(s[i] == 'M'){
            ans = ans + 1000;
        }
    }  

    return ans;
    }
};