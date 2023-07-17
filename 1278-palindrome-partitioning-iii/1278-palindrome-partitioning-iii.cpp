class Solution {
public:
   
    int palindromePartition(string s, int k) {
        //(start,end,k)
        function<int(int,int)>check=[&](int start,int end){
            int cnt=0;
            while(start<=end)if(s[start++]!=s[end--])cnt++;
            return cnt;
        };
        /*
        //My Solution.
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
        */
        
        //States can be reduced by taking few points in consideration.
        //current end will always be one index before the next start.
        //so instead of storing end we can calculate end from the value of next start.
        //THe below approach is state reduced. but an error still persists. 
        vector<vector<int>> dp(101,vector<int>(101,-1));
        function<int(int,int)> rec=[&](int start,int cnt){
            int n=s.length();
            if(start==n){
                if(!cnt)return 0;
                else return (int)(1e9-1);
            }
            // else if(start>=n && cnt)return (int)10000-1;
            
            int &ans=dp[start][cnt];
            // cout<<"ans "<<ans<<endl;
            if(ans==-1){
                ans=1e9-1;
                for(int end=start;end<n;end++){
                    int current_ans=1e9-1;
                    // cout<<start<<" - "<<end<<endl;
                    if(cnt)current_ans=check(start,end)+rec(end+1,cnt-1);
                    // cout<<"curr ans "<<current_ans<<endl;
                    ans=min(ans,current_ans);
                }
            }
            return ans;
        };
        
        return rec(0,k);
    }
};