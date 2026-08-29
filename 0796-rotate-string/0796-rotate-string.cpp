class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n = s.length();
        int m = goal.length();

        if(n != m){
            return false;
        }
        string temp = s + s;

        for(int i = 0; i < n; i++){
            if(temp.substr(i, n) == goal){
                return true;
            }
        }
        return false;
    }
};