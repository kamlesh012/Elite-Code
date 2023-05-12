class Solution{
public:
    long long rec(vector<vector<int>> &q,int i,vector<int> &dp){
        if(i>=q.size())return 0ll;
        if(dp[i]==-1){
            long long pick=0ll,notpick=0ll;
            pick=q[i][0]+rec(q,i+q[i][1]+1,dp);
            notpick=rec(q,i+1,dp);
            dp[i]=max(pick,notpick);
        }
        return dp[i];
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n=questions.size();
        
        //Memoized
        // vector<int> dp(n+1,-1);
        // return rec(questions,0,dp);
        
        //Tabulated
        vector<long long> dp(n,0ll);
        for(int i=n-1;i>=0;--i){
            long long points=0ll;
            if(i+questions[i][1]+1<n)points=dp[i+questions[i][1]+1];
            dp[i]=max(questions[i][0]+points,i+1<n?dp[i+1]:0ll);
        }
        return dp[0];   
    }
};
