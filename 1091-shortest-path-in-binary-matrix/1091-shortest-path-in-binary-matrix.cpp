class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.size();
        
        vector<vector<int>> dist(n,vector<int>(m,1000));
        
        if(grid[0][0]==0)dist[0][0]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,0}});
        
        while(!q.empty()){
            
            int dst=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            if(grid[x][y]==1)continue;
            
            if(x+1<n && dist[x+1][y]>dist[x][y]+1 && grid[x+1][y]!=1){
                dist[x+1][y]=dist[x][y]+1;
                q.push({dist[x+1][y],{x+1,y}});
            }
            
            if(x>0 && dist[x-1][y]>dist[x][y]+1 && grid[x-1][y]!=1){
                dist[x-1][y]=dist[x][y]+1;
                q.push({dist[x-1][y],{x-1,y}});
            }
            
            if(y+1<m && dist[x][y+1]>dist[x][y]+1 && grid[x][y+1]!=1){
                dist[x][y+1]=dist[x][y]+1;
                q.push({dist[x][y+1],{x,y+1}});
            }
            
            if(y>0 && dist[x][y-1]>dist[x][y]+1 && grid[x][y-1]!=1){
                dist[x][y-1]=dist[x][y]+1;
                q.push({dist[x][y-1],{x,y-1}});
            }
            
            if(x+1<n && y+1<n && dist[x+1][y+1]>dist[x][y]+1 && grid[x+1][y+1]!=1){
                dist[x+1][y+1]=dist[x][y]+1;
                q.push({dist[x+1][y+1],{x+1,y+1}});
            }
            
            if(x+1<n && y-1>-1 && dist[x+1][y-1]>dist[x][y]+1 && grid[x+1][y-1]!=1){
                dist[x+1][y-1]=dist[x][y]+1;
                q.push({dist[x+1][y-1],{x+1,y-1}});
            }
            
            if(x-1>-1 && y+1<n && dist[x-1][y+1]>dist[x][y]+1 && grid[x-1][y+1]!=1){
                dist[x-1][y+1]=dist[x][y]+1;
                q.push({dist[x-1][y+1],{x-1,y+1}});
            }
            
            if(x-1>-1 && y-1>-1 && dist[x-1][y-1]>dist[x][y]+1 && grid[x-1][y-1]!=1){
                dist[x-1][y-1]=dist[x][y]+1;
                q.push({dist[x-1][y-1],{x-1,y-1}});
            }  
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dist[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int ans=dist[n-1][n-1];
        return ans==1000?-1:ans+1;
    }
};