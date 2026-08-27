class Solution {
public:
    int mirrorDistance(int n) {
        
        int original = n;
        int rev = 0;
        
        while(n > 0){
            int ones = n%10;
            rev = rev*10 + ones;
            n = n/10;
        }
           int distance = abs(original - rev);
           
        return distance;
    }
};