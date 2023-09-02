class Solution {
public:
    bool predictTheWinner(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        function<int(int,int,bool)> rec=[&](int i,int j,bool turn){
            if(i>j)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            if(turn){
                dp[i][j]=max(rec(i+1,j,!turn)+piles[i],rec(i,j-1,!turn)+piles[j]);
            }
          else  dp[i][j]=min(rec(i+1,j,!turn)-piles[i],rec(i,j-1,!turn)-piles[j]);
            return dp[i][j];
        };
        int ans=rec(0,n-1,1);
        // cout<<ans<<endl;
        return ans>=0;
    }
};