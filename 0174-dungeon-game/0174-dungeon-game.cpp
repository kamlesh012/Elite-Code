class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        int dp[201][201];
        //Here: 
        //dp[i][j] represents the min starting health value knight should have 
        //at ith row & jth column of dungeon, if he wants to reach bottom right corner.
        
        //The (negative values)or demons are used as cost required at current cell.
        //The positive values are health but initially we still need at least 1 health
        //so cost required at positive health will not be 0,but 1.
        
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                //Base Case
                if(i==n-1 && j==m-1){
                    dp[i][j]=(a[i][j]>=0)?1:-a[i][j]+1;    
                }
                else{
                    int bottom=1e9,right=1e9;
                    if(i+1<n)bottom=dp[i+1][j];
                    if(j+1<m)right=dp[i][j+1];
                    
                    //cost = min from both directions + value at current cell.
                    int cost=min(bottom,right)-a[i][j];
                    
                    if(cost<=0)cost=1;
                    dp[i][j]=cost;
                    
                }
            }
        }
        return dp[0][0];
    }
};

//Took Hint from this blog;
// https://leetcode.com/problems/dungeon-game/discuss/745340/post-Dedicated-to-beginners-of-DP-or-have-no-clue-how-to-start