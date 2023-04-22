
class Solution {
public:
     int lps(string &s,int i,int j,vector<vector<int>>& dp){
        if(i==j)return 1;
        if(i>j)return 0;
        if(dp[i][j]==-1){
            if(s[i]==s[j])return dp[i][j]=2+lps(s,i+1,j-1,dp);
            else {
                return dp[i][j]=max(lps(s,i+1,j,dp),lps(s,i,j-1,dp));
            }
        }
        return dp[i][j];
    }
    
//     int rec(int i,int j,string s,vector<vector<int>> &dp){
//         if(i==j){
//             return 0;
//         }
//         if(i>j)return INT_MAX;
//         if(dp[i][j]==-1){
            
//             if(s[i]==s[j]){
//                 cout<<s<<endl;
//                 cout<<s[i]<<" = "<<s[j]<<endl;
//                 return dp[i][j]=rec(i+1,j-1,s,dp);
//             }
//             else{
//                 cout<<s<<endl;
//                 cout<<s[i]<<" != "<<s[j]<<endl;
//                 return dp[i][j]=1+min(rec(i+1,j,s,dp),rec(i,j-1,s,dp));
//             }
//         }
//         return dp[i][j];
//     }
    
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        //using LPS;
        //min insertions to make palindrome=|string| - LPS(string);
        
        return n-lps(s,0,n-1,dp);
    }
};