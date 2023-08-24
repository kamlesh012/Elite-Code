class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        
        //dp[i][j] represents the number of square submatrices ending at index i,j;
        
        vector<vector<int>> dp=mat;
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left=0,diag=0,up=0;
                if(i>0)up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                if(i>0 && j>0)diag=dp[i-1][j-1];
                
                if(dp[i][j])dp[i][j]+=min(up,min(left,diag));
                sum+=dp[i][j];
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return sum;
    }
};