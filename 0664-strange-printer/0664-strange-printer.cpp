class Solution {
public:
    int strangePrinter(string s) {
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        
        function<int(int,int)> rec=[&](int l,int r){
            
            if(l==r)return 1;   //if single character left
            if(l>r)return 0;
            
            int &ans=dp[l][r];
            if(ans!=-1)return ans;

            int notpick=0,pick=1e9;
            int new_l=l+1;
            while(new_l<=r && s[new_l]==s[l])new_l++;

            notpick=1+rec(new_l,r);
            
            for(int j=new_l;j<=r;j++){
                if(s[j]==s[l]){        
                    int right_range=rec(new_l,j-1);
                    int remaining_range=rec(j,r);
                    pick=min(pick,right_range+remaining_range);
                }
            }
            
            return ans=min(pick,notpick);
        };
        
        return rec(0,n-1);
    }
};