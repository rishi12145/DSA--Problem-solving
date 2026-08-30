class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length();
        int m = t.length();

        unordered_map<char, int> mp;

        if(n != m){
            return false;
        }

        for(int  i = 0; i < n ; i++){
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto check: mp){
            if(check.second != 0){
                return false;
            }
        }
        return true;
    }
};