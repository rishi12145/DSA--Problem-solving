class Solution {
public:
    
    double square(double x, long long n){
        if(n == 0){
            return 1;
        } 

        double half = square(x, n/2);
         
         if(n % 2 ==  0){
            return half * half;
        }
            return x * half * half;
    }
    
    double myPow(double x, int n) {

        long long num = n;

        if(num < 0){
            return 1/ square(x, -num);
        }
        return square(x, num);   
    }
};