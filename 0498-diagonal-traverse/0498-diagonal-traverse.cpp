class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;

        for(int diagonal = 0; diagonal < m+n-1; diagonal++){

            vector<int> temp;

            for(int i = 0; i < m; i++){
                int j = diagonal - i;

                if(j >= 0 && j < n){
                    temp.push_back(mat[i][j]);
                }
            }

            if(diagonal % 2 == 0){
                reverse(temp.begin(), temp.end());
            }
            for(int i = 0; i < temp.size();i++){
                ans.push_back(temp[i]);
            }
        }
        return ans;

        
    }
};