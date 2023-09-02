class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        //Observation:
        return true;
        
        //OR using DP;
        
        int n=piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        //Consider this test case:
        //[3,1,2,1]
        //3+(1,2,1)
        //1+(2,1)
        //2+(1)
        //Overall-> 3+1+2+1 
        //if we will store different sums for alex & bob then we couldn't distinguish whose score is which one as after recursive calls they will be added.
        //so instead of that bob will use negative sum
        //means we are storing the difference b/w there score for each (i,j)
        //for bob negaitve means it's opposite of alice's score.
        //Now Overall-> 3-1+2-1
        //here + as alice's score - are bob's score.
        //we can see alice is clearly the winner here.
        
        function<int(int,int,bool)> rec=[&](int i,int j,bool turn){
            if(i>j)return 0;
            if(dp[i][j]!=-1)return dp[i][j];
            if(turn){
                dp[i][j]=max(rec(i+1,j,!turn)+piles[i],rec(i,j-1,!turn)+piles[j]);
            }
          else  dp[i][j]=max(rec(i+1,j,turn)-piles[i],rec(i,j-1,!turn)-piles[j]);
            return dp[i][j];
        };
        return rec(0,n-1,1)>0;
    }
};