class Solution {
public:
    
    string smallestGreaterPerm(vector<int> cnt, const string& target) {
        int n = target.size();
        int last_i = -1, last_c = -1;
        vector<int> last_state;

        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';
            int found = -1;
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) { found = c; break; }
            }
            if (found != -1) {
                last_i = i;
                last_c = found;
                last_state = cnt;
            }
            if (cnt[t] > 0) cnt[t]--;
            else break;
        }

        if (last_i == -1) return "";

        vector<int> finalCnt = last_state;
        finalCnt[last_c]--;

        string result = target.substr(0, last_i);
        result += char('a' + last_c);
        for (int c = 0; c < 26; c++)
            result += string(finalCnt[c], char('a' + c));
        return result;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        
        int oddCount = 0, oddChar = -1;
        for (int c = 0; c < 26; c++)
            if (cnt[c] % 2 != 0) { oddCount++; oddChar = c; }

        if ((n % 2 == 0 && oddCount != 0) || (n % 2 == 1 && oddCount != 1))
            return "";

        int P = n / 2;
        vector<int> halfCnt(26, 0);
        for (int c = 0; c < 26; c++) halfCnt[c] = cnt[c] / 2;

        char mid = (n % 2 == 1) ? char('a' + oddChar) : '\0';
        string targetPrefix = target.substr(0, P);

        
        vector<int> tempCnt = halfCnt;
        bool formable = true;
        for (char ch : targetPrefix) {
            int c = ch - 'a';
            if (tempCnt[c] > 0) tempCnt[c]--;
            else { formable = false; break; }
        }

        if (formable) {
            string A = targetPrefix;
            if (n % 2 == 1) A += mid;
            string rev = targetPrefix;
            reverse(rev.begin(), rev.end());
            A += rev;
            if (A > target) return A;
        }

        
        string x = smallestGreaterPerm(halfCnt, targetPrefix);
        if (x.empty()) return "";

        string A = x;
        if (n % 2 == 1) A += mid;
        string rev = x;
        reverse(rev.begin(), rev.end());
        A += rev;
        return A;
    }
};