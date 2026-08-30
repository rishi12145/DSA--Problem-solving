class Solution {
public:
    string frequencySort(string s) {

        int freq[256] = {0};

        for(int i = 0; i < s.length(); i++){
            freq[s[i]]++;
        }

        vector<vector<char>> bucket(s.length() + 1);

        for(int i = 0; i < 256; i++){
            if(freq[i] > 0){
                bucket[freq[i]].push_back(char(i));
            }
        }

        string ans = "";

        for(int i = s.length(); i >= 1; i--){
            for(int j = 0; j < bucket[i].size(); j++){
                for(int k = 0; k < i; k++){
                    ans += bucket[i][j];
                }
            }
        }

        return ans;
    }
};