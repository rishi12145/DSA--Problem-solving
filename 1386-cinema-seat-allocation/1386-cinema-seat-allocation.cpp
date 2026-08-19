class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> reserved;

        for(int i = 0; i < reservedSeats.size(); i++)
        {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            reserved[row].insert(seat);
        }

        int ans = (n - reserved.size()) * 2;

        for(auto x : reserved)
        {
            int row = x.first;

            bool left = true;
            bool middle = true;
            bool right = true;

            for(int seat = 2; seat <= 5; seat++)
            {
                if(reserved[row].count(seat))
                    left = false;
            }

            for(int seat = 4; seat <= 7; seat++)
            {
                if(reserved[row].count(seat))
                    middle = false;
            }

            for(int seat = 6; seat <= 9; seat++)
            {
                if(reserved[row].count(seat))
                    right = false;
            }

            if(left && right)
                ans += 2;
            else if(left || middle || right)
                ans += 1;
        }

        return ans;
    }
};