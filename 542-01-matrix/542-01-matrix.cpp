class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        //DP->NEW WAY LEARNT
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        //First Iterate for Top  & Left SIde
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)dp[i][j]=0;
                else{
                    int one=1e5,two=1e5;
                    if(i-1>=0)one=dp[i-1][j]+1;
                    if(j-1>=0)two=dp[i][j-1]+1;
                    dp[i][j]=min({dp[i][j],one,two});
                }
            }
        }
        
        //Then for Bottom & Right side from Bottom To Top
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                if(grid[i][j]){
                    int one=1e5,two=1e5;
                    if(i+1<n)one=dp[i+1][j]+1;
                    if(j+1<m)two=dp[i][j+1]+1;
                    dp[i][j]=min({dp[i][j],one,two});
                }
            }
        }
        //Why? Not NOrmal DP
        //Because we don't know from which direction to traverse.
        //so choosing all the directions & picking the minimum of all.
        return dp;
        
        //Multi-Source BFS.
        //Shortest Paths.
        //Same as Rotten Tomatoes.
            /*
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0)),distance(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    distance[i][j]=0;
                }
            }
        }
        
        while(!q.empty()){
            
            auto curr=q.front();
            q.pop();
            int x=curr.first,y=curr.second;
            visited[x][y]=1;
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    if((i && !j ) || (!i && j)){
                        int cx=x+i,cy=y+j;
                        if(cx>=0 && cx<n && cy>=0 && cy<m && !visited[cx][cy] && grid[cx][cy]) {
                            distance[cx][cy]=min(distance[x][y]+1,distance[cx][cy]);
                            q.push({cx,cy});
                        }
                    }
                }
            }
        }
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//             cout<<visited[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<endl;
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//             cout<<distance[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<endl;
        
//         int ans=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1 && !visited[i][j])
//                 {
//                     return -1;
//                 }
//                 else if(grid[i][j]==1)
//                     {
//                     ans=max(ans,distance[i][j]);
//                 }
//             }
//         }
//          return ans;
        
        return distance;
        */
    }
};