class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

    int n = grid.size();
    int m = grid[0].size();

     vector<vector<int>> visi(n,vector<int> (m,0));
    queue<pair<pair<int,int>,int>> q;

     int count =0;
     int fresh =0;
     for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(grid[i][j]== 2){
                q.push({{i,j},0});
            visi[i][j] = 1;
            }
             if(grid[i][j] == 1){
                fresh++;
            }

        }
     }
     int tm =0;
     int delrow[] ={-1,0,0,+1};
     int delcol[] = {0,-1,+1,0};
int rotted =0;
     while(!q.empty()){
        int r = q.front().first.first;
            int c = q.front().first.second;
        int t = q.front().second;
           tm = max(tm,t);
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m
            && visi[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol},t+1});
                visi[nrow][ncol] = 1;
                rotted ++;
            }
        }
     } 

     return fresh == rotted ? tm : -1;

    //  for(int i=0;i<n;i++){
    //     for(int j =0 ; j<m;j++){
    //         if(visi[i][j] != 1 && grid[i][j] == 1){
    //             return -1;
    //         }
    //     }
     
// return tm;
    }
};