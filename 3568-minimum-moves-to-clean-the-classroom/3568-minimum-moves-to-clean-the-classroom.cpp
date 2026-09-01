class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int n = classroom.size();
        int m = classroom[0].size();

        int startRow = 0;
        int startCol = 0;

        vector<pair<int,int>> litter;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(classroom[i][j] == 'S')
                {
                    startRow = i;
                    startCol = j;
                }

                if(classroom[i][j] == 'L')
                {
                    litter.push_back({i, j});
                }
            }
        }

        int totalLitter = litter.size();

        if(totalLitter == 0)
            return 0;

        vector<vector<int>> litterId(n, vector<int>(m, -1));

        for(int i = 0; i < totalLitter; i++)
        {
            litterId[litter[i].first][litter[i].second] = i;
        }

        int totalMasks = 1 << totalLitter;

        vector<vector<vector<int>>> best(
            n, vector<vector<int>>(m, vector<int>(totalMasks, -1))
        );

        queue<tuple<int,int,int,int>> q;

        q.push({startRow, startCol, energy, 0});
        best[startRow][startCol][0] = energy;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int moves = 0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto [row, col, currentEnergy, mask] = q.front();
                q.pop();

                if(mask == totalMasks - 1)
                    return moves;

                for(int d = 0; d < 4; d++)
                {
                    int newRow = row + dr[d];
                    int newCol = col + dc[d];

                    if(newRow < 0 || newRow >= n ||
                       newCol < 0 || newCol >= m)
                        continue;

                    if(classroom[newRow][newCol] == 'X')
                        continue;

                    if(currentEnergy == 0)
                        continue;

                    int newEnergy = currentEnergy - 1;
                    int newMask = mask;

                    if(classroom[newRow][newCol] == 'R')
                    {
                        newEnergy = energy;
                    }

                    if(classroom[newRow][newCol] == 'L')
                    {
                        int id = litterId[newRow][newCol];
                        newMask = mask | (1 << id);
                    }

                    if(newEnergy > best[newRow][newCol][newMask])
                    {
                        best[newRow][newCol][newMask] = newEnergy;

                        q.push({
                            newRow,
                            newCol,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};