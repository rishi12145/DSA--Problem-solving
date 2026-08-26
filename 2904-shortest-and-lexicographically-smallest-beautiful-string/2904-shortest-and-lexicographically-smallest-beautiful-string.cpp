class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        int n = s.length();
        string ans = "";

        int minlen = n+1;

        for(int i = 0; i <n; i++){
            int count = 0;
        
        for(int j = i; j <n; j++){
            if(s[j] == '1'){
                count++;
            }
            if(count == k){
                string temp = s.substr(i, j-i+1);
                if(temp.length() < minlen){
                    minlen = temp.length();
                    ans = temp;
                }
                else if(temp.length() == minlen){
                    if(temp <ans){
                        ans = temp;
                    }
                }
                break;
            }
          } 
        }
        return ans;
    }
};