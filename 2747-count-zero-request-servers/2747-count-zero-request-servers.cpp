class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        int L = logs.size();
        int Q = queries.size();

        // Sort logs by time
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        // Store query and original index
        vector<pair<int,int>> q;

        for(int i = 0; i < Q; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> ans(Q);
        vector<int> freq(n + 1, 0);

        int left = 0;
        int right = 0;
        int active = 0;

        for(int i = 0; i < Q; i++) {

            int end = q[i].first;
            int start = end - x;
            int idx = q[i].second;

            // Add logs within the ending time
            while(right < L && logs[right][1] <= end) {

                int server = logs[right][0];

                if(freq[server] == 0) {
                    active++;
                }

                freq[server]++;
                right++;
            }

            // Remove logs outside the starting time
            while(left < right && logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if(freq[server] == 0) {
                    active--;
                }

                left++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
};