class Solution {
public:
    bool judgeCircle(string moves) {
        
        int n = moves.length();
        int x = 0;
        int y = 0;
        
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            if(moves[i] == 'U'){
               y++;
            }
            if(moves[i] == 'R'){
                x++;
            }
            if(moves[i] == 'L'){
                x--;
            }
            if(moves[i] == 'D'){
                y--;
            }
        }    
          if(x == 0 && y ==0){
            return true;
          }
          else{
            return false; 
          }
        return -1;
    }
};