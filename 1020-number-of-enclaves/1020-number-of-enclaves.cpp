class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0)),distance(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        
        int totalland=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1 ) && grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=1;
                }
                if(grid[i][j]==1)totalland++;
            }
        }
        
        int boundaryland=0;
        vector<int> move={0,1,0,-1,0};
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first,y=curr.second;
            boundaryland++;
            visited[x][y]=1;
            for(int i=0;i<4;i++){
                int cx=move[i]+x;
                int cy=move[i+1]+y;
                if(cx>=0 && cx<n && cy>=0 && cy<m && !visited[cx][cy] && grid[cx][cy]){
                    q.push({cx,cy});
                    visited[cx][cy]=1;
                }
            }
        }
        
        return totalland-boundaryland;
    }
};