class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1,
                       vector<vector<int>>& img2) {

        int n = img1.size();

        int ans = 0;

        for (int rowShift = -(n - 1);
             rowShift <= n - 1;
             rowShift++) {

            for (int colShift = -(n - 1);
                 colShift <= n - 1;
                 colShift++) {

                int overlap = 0;

                for (int i = 0; i < n; i++) {

                    for (int j = 0; j < n; j++) {

                       
                        if (img1[i][j] == 1) {

                            int newRow = i + rowShift;
                            int newCol = j + colShift;

                            // Check if translated position
                            // is inside img2
                            if (newRow >= 0 && newRow < n &&
                                newCol >= 0 && newCol < n) {

                                // Check overlap
                                if (img2[newRow][newCol] == 1) {
                                    overlap++;
                                }
                            }
                        }
                    }
                }

                ans = max(ans, overlap);
            }
        }

        return ans;
    }
};