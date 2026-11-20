class Solution {
public:

void bfs(int row,int col,vector<vector<char>>& grid , vector<vector<int>> &visi,int delrow[],int delcol[]){

    visi[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});

    int n = grid.size();
    int m = grid[0].size();

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i =0 ;i< 4;i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >=0 && nrow<n  && ncol>=0 && ncol< m 
            && grid[nrow][ncol]== '1' && !visi[nrow][ncol]){
                visi[nrow][ncol]=1;
                q.push({nrow,ncol});
            }

        }
    
    }

}


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        int count =0;
        int delrow[] = {-1,0,0,+1};
        int delcol[] = {0,-1,+1,0};

        for(int i =0;i<n;i++){
            for(int j =0 ; j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i,j,grid,vis,delrow,delcol);
                }
            }
        }
        return count;
    }
};