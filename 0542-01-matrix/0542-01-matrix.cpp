class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // 1. Fixed duplicate declaration: one for dist, one for vis
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pair<pair<int, int>, int>> q;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Note: Use 'grid[i][j] == 0' for LeetCode 542, 
                // or 'grid[i][j] == 1' for the GFG variant.
                if (grid[i][j] == 0) { 
                    // 2. Added nested braces for pair<pair<int,int>, int>
                    q.push({{i, j}, 0}); 
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        
        int delrow[] = {-1, 0, 0, +1};
        int delcol[] = {0, -1, +1, 0};
        
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            
            dist[row][col] = steps;
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    // 3. Push {nrow, ncol} instead of {i, j} with proper braces
                    q.push({{nrow, ncol}, steps + 1}); 
                    // 4. Fixed typo 'nco' -> 'ncol'
                    vis[nrow][ncol] = 1; 
                }
            }
        }
        
        return dist;
    }
};
