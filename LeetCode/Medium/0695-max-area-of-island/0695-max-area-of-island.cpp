class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        int dRow[] = {-1, 1, 0, 0};
        int dCol[] = {0, 0, -1, 1};

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 1) {
                    int currarea = 0;
                    queue<pair<int, int>> q;
                    
                    q.push({r, c});
                    grid[r][c] = 0; 
                    
                    while (!q.empty()) {
                        auto [currR, currC] = q.front();
                        q.pop();
                        currarea++; 

                        for (int i = 0; i < 4; i++) {
                            int nRow = currR + dRow[i];
                            int nCol = currC + dCol[i];

                            if (nRow >= 0 && nRow < rows && nCol >= 0 && nCol < cols && grid[nRow][nCol] == 1) {
                                q.push({nRow, nCol});
                                grid[nRow][nCol] = 0; 
                            }
                        }
                    }
                    maxarea = max(maxarea, currarea);
                }
            }
        }
        return maxarea;
    }
};