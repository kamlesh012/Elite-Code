class Solution {
public:
    int countDigitOne(int n) {
        
        int dp[10][2][10];
        memset(dp,-1,sizeof dp);
        string upper=to_string(n);
        
        function<int(int i,int turn,int one)> digit=[&](int i,int turn,int one){
            if(i==upper.size())return one;
    
            int &ans=dp[i][turn][one];
            if(ans!=-1)return ans;
            
            ans=0;            
            char up=turn?'9':upper[i];
            for(char c='0';c<=up;c++){
                if(c=='1')ans+=digit(i+1,turn|(c!=up),one+1);
                else ans+=digit(i+1,turn|(c!=up),one);
            }
            return ans;
        };
        
        return digit(0,0,0);
    }
};