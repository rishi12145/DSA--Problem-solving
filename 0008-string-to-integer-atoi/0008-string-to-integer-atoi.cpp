class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        long long ans = 0;
        int sign = 1;

        int i = 0;

 
        while(i < n && s[i] == ' ') {
            i++;
        }


        if(i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+') {
            sign = 1;
            i++;
        }

        while(i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            
            if(ans > INT_MAX / 10 ||
               (ans == INT_MAX / 10 && digit > INT_MAX % 10)) {

                if(sign == -1)
                    return INT_MIN;
                else
                    return INT_MAX;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};