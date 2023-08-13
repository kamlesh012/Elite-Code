class Solution {
public:
    vector<int> dir1={0,1,-1,0};
    vector<int> dir2={1,0,0,-1};
    vector<int> path;
    int back(int r,int c,vector<vector<int>> &grid,vector<vector<int>> &vis,int steps){
        if(grid[r][c]==2){
            // vis[r][c]=0;
            cout<<" end "<<steps<<endl;
            for(auto i:path){
                cout<<i<<" ";
            }
            cout<<endl;
            return !steps;
        }
        int n=grid.size(),m=grid[0].size();
        
        int ans=0;
        for(int i=0;i<4;i++){
            int x=r+dir1[i];
            int y=c+dir2[i];
            // cout<<" row "<<r<<" col "<<c<<" cx "<<x<<" cy "<<y<<endl;
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!=-1 && !vis[x][y] && steps>0){
            // cout<<grid[x][y]<<" "<<vis[x][y]<<endl;
                vis[x][y]=1;
                path.push_back(x);
                path.push_back(y);
                ans+=back(x,y,grid,vis,steps-1);
                path.pop_back();
                path.pop_back();
                vis[x][y]=0;
            }
        }
        return ans;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid){
        
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int steps=0;
        int sr=0,sc=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                steps+=!grid[i][j];
                if(grid[i][j]==1){
                    sr=i,sc=j;
                }
            }
        }
        vis[sr][sc]=1;
        // cout<<" steps "<< steps<<endl;
        return back(sr,sc,grid,vis,steps+1);
    }
};