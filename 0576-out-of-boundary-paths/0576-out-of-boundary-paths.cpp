class Solution {
public:
    int findPaths(int m, int n, int maxMove, int r, int c) {
        int mod=1e9+7;
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
//         pi & pj were supposed to be parent cell of i,j
        //but they are not needed because if a cell visits its parents back, then
        // that would be a different path as seen in sample test case 2, moves also be exhausted & that would be a different dp state, not the previosu one.
        //so there won't be any infinte loop  problem.
        
        function<int(int,int,int,int,int)> paths=[&](int i,int j,int pi,int pj,int moves){
            if(i<0 || i>=m || j<0 || j>=n)return 1;
            if(moves==0)return 0;
            if(dp[i][j][moves]!=-1){
                return dp[i][j][moves];
            }
            int ans=0;
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    if((x && !y) || (y && !x)){
                        int ci=x+i,cj=y+j;   
                        ans=((ans%mod)+(paths(ci,cj,i,j,moves-1)%mod))%mod;
                    }
                }
            }
            return dp[i][j][moves]=ans;
        };
        return paths(r,c,r,c,maxMove);
        
//         MLE BFS
        
//         queue<pair<int,int>> q;
//         q.push({r,c});
//         int paths=0;
//         while(q.size()){
//             int sz=q.size();
//             if(!maxMove)break;
//             maxMove--;
//             while(sz--){
//                 pair<int,int> top=q.front();
//                 q.pop();
                
//                 int f=top.first,s=top.second;        
//                 for(int i=-1;i<=1;i++){
//                     for(int j=-1;j<=1;j++){
//                         if((i && !j) || (j && !i)){
//                             int tf=f+i,ts=s+j;
//                             if(tf>=0 && tf<m && ts>=0 && ts<n){
//                                 q.push({tf,ts});
//                             }
//                             else {
//                                 paths++;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return paths;
        
    }
};