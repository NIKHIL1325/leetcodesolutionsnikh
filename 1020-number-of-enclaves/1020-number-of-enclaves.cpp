class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;

        int n = grid.size();
        int m =  grid[0].size();
        vector<vector<int>> visi(n,vector<int> (m,0));
        
       


// Top and Bottom rows (j goes from 0 to m-1)
for (int j = 0; j < m; j++) {
    if (grid[0][j] == 1) {
        q.push({0, j});
        visi[0][j] = 1;
    }
    if (grid[n - 1][j] == 1) {
        q.push({n - 1, j});
        visi[n - 1][j] = 1;
    }
}

// Left and Right columns (i goes from 0 to n-1)
for (int i = 0; i < n; i++) {
    if (grid[i][0] == 1) {
        q.push({i, 0});
        visi[i][0] = 1;
    }
    if (grid[i][m - 1] == 1) {
        q.push({i, m - 1});
        visi[i][m - 1] = 1;
    }
}

int delrow[]= {-1,0,0,+1};
int delcol[]= {0,-1,+1,0};

while(!q.empty()){
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for(int i= 0 ; i<4;i++){
        int nrow = row  + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >=0 && nrow<n && ncol>=0 && ncol<m &&
        grid[nrow][ncol] == 1&& visi[nrow][ncol] == 0){
            q.push({nrow,ncol});
            visi[nrow][ncol] = 1;
        }
    }
}

int cnt =0 ;
for(int i =0 ;i<n ;i++){
    for(int j =0 ;j<m ; j++){
        if(grid[i][j] == 1 && visi[i][j] == 0) cnt++;
    }
}

return cnt;






        
    }
};