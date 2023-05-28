class Solution {
public:
    long long minimumCost(string s) {
        int n=s.length();
        vector<long long> pre(n,0ll),suf(n,0ll);
        
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                pre[i]=pre[i-1]+(i);
            }
            else pre[i]=pre[i-1];
        }
        
        for(int i=n-2;i>=0;--i){
            if(s[i]!=s[i+1]){
                suf[i]=suf[i+1]+(n-i-1);
            }
            else suf[i]=suf[i+1];
        }
        long long ans=2e18+9;
        for(int i=0;i<n;i++){
            ans=min(ans,pre[i]+suf[i]);
        }
        
        return ans;
        
    }
};