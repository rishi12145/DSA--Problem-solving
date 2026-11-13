class Solution {
public:
    bool threeFibonacciSum(int n) {

        vector<int> f;

        f.push_back(0);
        f.push_back(1);
        f.push_back(1);

        while (true) {

            int m = f.size();

            int sum = f[m - 3] + f[m - 2] + f[m - 1];

            if (sum == n)
                return true;

            if (sum > n)
                return false;

            f.push_back(f[m - 2] + f[m - 1]);
        }
        return false;
    }
};
