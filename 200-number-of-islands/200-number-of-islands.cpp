class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        visited[i][j]++;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                
                if((!x && y) || (x && !y)){
                    int r=x+i,c=y+j;
                    if(r>=0 && r<m && c>=0 && c<n && grid[r][c]=='1' && !visited[r][c]){
                        dfs(grid,visited,r,c);
                    }
                }
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int component=0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid,visited,i,j);
                    component++;
                }
            }
        }
        return component;
    }
};