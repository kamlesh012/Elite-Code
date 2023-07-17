class Solution {
public:
   
    int palindromePartition(string s, int k) {
        //(start,end,k)
        function<int(int,int)>check=[&](int start,int end){
            int cnt=0;
            while(start<=end)if(s[start++]!=s[end--])cnt++;
            return cnt;
        };
        
        vector<vector<vector<int>>> dp(101,vector<vector<int>>(101,vector<int>(101,-1)));
        
        function<int(int,int,int)> rec=[&](int start,int end,int cnt){
            int n=s.length();
            if(start==n && !cnt)return 0;
            else if(end==n)return (int)1e9-1;
            int &ans=dp[start][end][cnt];
            
            if(ans==-1){
                
                int end_here=INT_MAX,not_end_here=INT_MAX;

                not_end_here=rec(start,end+1,cnt);

                if(cnt)end_here=check(start,end)+rec(end+1,end+1,cnt-1);

                ans=min(end_here,not_end_here);
            }
            return ans;
        };
        
        return rec(0,0,k);
    }
};