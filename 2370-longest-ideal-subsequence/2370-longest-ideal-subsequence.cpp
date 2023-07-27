class Solution {
public:
    int longestIdealString(string s, int k) {
        
        //Traditional LIS won't work.
        //Tried the BS one only to end up in vain.
        //Got Messy & won't work as a character might replace another which might have given LIS in future. Try this testcase  eduktdb 
        //BS LIS o/p=4. COrrect ans=5;
        //Here a variation of LIS will be used.
        // dp[i] represents the longest inceasing subsequence with ending character as i.
        //we will only search till i-k & i+k
        
        vector<int> dp(26,0);
        //Initially setting LIS as zero. SO that the elements that hasn't been encountered in s till now don't count.
        
        int ans=1;//min ans
        
        for(int i=0;i<s.length();i++){  //iterating over all the characters
            
            int c=s[i]-'a';     //current character
            dp[c]++;        //adding Current element to LIS.
            
            for(int j=0;j<26;j++){
                //iterating over all the characters in smaller than k distance
                   if(c!=j && abs(j-c)<=k)
                        dp[c]=max(dp[c],dp[j]+1);
            }
            
            ans=max(ans,dp[c]);
        }
        return ans;
    }
};