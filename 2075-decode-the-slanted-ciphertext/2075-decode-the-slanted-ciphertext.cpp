class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int n = rows;
        int m = encodedText.size() / rows;
        
        string temp;
        temp.reserve(encodedText.size());

        for(int j = 0; j < m; j++) {
            
            int i = 0;
            int col = j;
            
            while(i < n && col < m) {
                temp += encodedText[i * m + col];
                i++;
                col++;
            }
        }
        
        while(!temp.empty() && temp.back() == ' ') {
            temp.pop_back();
        }
        
        return temp;
    }
};