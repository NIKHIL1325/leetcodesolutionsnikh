class Solution {
public:
    void dfs (int node , vector<int> adjL[],vector<int> & visi ){
        visi[node] = 1;

        for(auto it : adjL[node]){
            if(!visi[it]){
                dfs(it,adjL,visi);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<int> adjL[n+1];
        for(int i=0;i<n;i++){
            for(int j =0 ; j<m ; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adjL[i].push_back(j);
                           adjL[j].push_back(i);
                }
            }
        }

        int count =0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
                dfs(i,adjL,vis);
            }
        }
       return count; 
    }
};