
class Solution {
public:
     int using_lps(string &s,int i,int j,vector<vector<int>>& dp){
        if(i==j)return 1;
        if(i>j)return 0;
        if(dp[i][j]==-1){
            if(s[i]==s[j])return dp[i][j]=2+using_lps(s,i+1,j-1,dp);
            else {
                return dp[i][j]=max(using_lps(s,i+1,j,dp),using_lps(s,i,j-1,dp));
            }
        }
        return dp[i][j];
    }
    
    int without_lps(int i,int j,string &s,vector<vector<int>> &dp){
        if(i==j)return 0;
        
        //the second base case is important.
        //was stuck in this for too long.
        //remember why we should'nt return INT_MAX?
        
        //because after forming all the palindromes if i crosses j (i>j)
        //then if we return INT_MAX there progress will be reset,means the palindromes that we have inserted till now will not count as instead of returning +1 we are returning INT_MAX.which will be ignored by min function.
        
        //on ther hand if we return 0 then it will stop recursino from proceeding forward & also not affect the previous characters that have been inserted.
        if(i>j)return 0;
        
        if(dp[i][j]==-1){
            
            if(s[i]==s[j]){
                // cout<<s<<endl;
                // cout<<s[i]<<" = "<<s[j]<<endl;
                return dp[i][j]=without_lps(i+1,j-1,s,dp);
            }
            else{
                // cout<<s<<endl;
                // cout<<s[i]<<" != "<<s[j]<<endl;
                return dp[i][j]=1+min(without_lps(i+1,j,s,dp),without_lps(i,j-1,s,dp));
            }
        }
        return dp[i][j];
    }
    
    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        //using LPS;
        //min insertions to make palindrome=|string| - LPS(string);
        // return n-using_lps(s,0,n-1,dp);
        
        //without LPS:
        //standard DP rec->memo
        return without_lps(0,n-1,s,dp);
        
    }
};