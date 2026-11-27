class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // 1. Check if start or end is blocked
        if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return -1;
        
        // 2. Handle 1x1 grid edge case
        if (n == 1 && m == 1) return 1;

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, pair<int, int>>> q;
        
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nrow = r + i;
                    int ncol = c + j;
                    
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                        grid[nrow][ncol] == 0 && d + 1 < dist[nrow][ncol]) {
                        
                        dist[nrow][ncol] = d + 1;
                        
                        // Check for 0-indexed destination (n-1, m-1)
                        if (nrow == n - 1 && ncol == m - 1) return d + 1;
                        
                        q.push({d + 1, {nrow, ncol}});
                    }
                }
            }
        }
        return -1;
    }
};
