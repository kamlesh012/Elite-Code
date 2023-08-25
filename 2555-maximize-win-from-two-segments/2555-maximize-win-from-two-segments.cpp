class Solution {
public:
    int maximizeWin(vector<int>& prz, int k)
    {
       int n=prz.size(),j=0,ans=0,one=0,two=0,start=0;
        
        //Finding Second Segment Using DP.
        vector<int> dp(n+1,-1);
        function<int(int i)> rec=[&](int i){
            if(i>=n)return 0;
            if(dp[i]!=-1)return dp[i];
            
            int notpick=rec(i+1);
            int ind=upper_bound(prz.begin()+i,prz.end(),prz[i]+k)-(prz.begin()+i);
            return dp[i]=max(notpick,ind);
        };
        
        
        //Finding Starting Segment Using Sliding Window.
        for(int i=0;i<n;i++){
            while(j<n && prz[i]-prz[j]>k)j++;
            if((i-j+1)>one){
                one=i-j+1;
            }
            two=rec(i+1);
            // cout<<mx<<" "<<mx2<<" "<<i<<endl;
            ans=max(ans,one+two);
        }
        
        return ans;
    }
};