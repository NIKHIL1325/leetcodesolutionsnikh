class Solution {
public:
void dfs (int row , int col, vector<vector<int>>&  image, vector<vector<int>>&  ans , int newcolor, int inicolr , int delrow[],int delcol[]){
 
    ans[row][col] = newcolor;
    int n = image.size();
    int m = image[0].size();

    for(int i =0;i<4;i++){
        int nrow = row  + delrow[i];
        int ncol = col + delcol[i];

        if(nrow >=0 && nrow<n && ncol>=0 && ncol<m 
        && image[nrow][ncol] == inicolr && ans[nrow][ncol] != newcolor){
            dfs(nrow,ncol,image,ans , newcolor , inicolr,delrow,delcol);
        }
     
    }
}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int inicolor = image[sr][sc];
        

        vector<vector<int>> ans = image;
        int delrow[] = {-1,0,0,+1};
        int delcol[] = {0,+1,-1,0};
        dfs(sr,sc,image ,ans, color,inicolor,delrow,delcol);

        return ans;
    }
};