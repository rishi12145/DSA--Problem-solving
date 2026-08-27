class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char ch : s) cnt[ch - 'a']++;

        int last_i = -1, last_c = -1;
        vector<int> last_state;

        for (int i = 0; i < n; i++) {
            int t = target[i] - 'a';

            // find smallest available letter greater than target[i]
            int found = -1;
            for (int c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    found = c;
                    break;
                }
            }

            if (found != -1) {
                last_i = i;
                last_c = found;
                last_state = cnt; // snapshot before consuming target[i]
            }

            // try to extend exact-match prefix with target[i]
            if (cnt[t] > 0) {
                cnt[t]--;
            } else {
                break;
            }
        }

        if (last_i == -1) return "";

        vector<int> finalCnt = last_state;
        finalCnt[last_c]--;

        string result = target.substr(0, last_i);
        result += char('a' + last_c);

        for (int c = 0; c < 26; c++) {
            result += string(finalCnt[c], char('a' + c));
        }

        return result;
    }
};