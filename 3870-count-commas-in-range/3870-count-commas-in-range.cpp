class Solution {
public:
    int countCommas(int n) {

        for(int i = 0; i <n; i++){
            if(n > 999){
                return n-999;
            }
            else{
                return 0;
            }
        }
        return -1;
    }
};