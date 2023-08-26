class Solution {
public:
//         Digit DP - Clean Solution
    int countDigitOne(int n) {
        int dp[10][2][10];
        memset(dp,-1,sizeof dp);
        string upper_limit=to_string(n);
        
        /*
         dp[i][tight][countOnes] = Count of all ones in position range [i....n-1] of all numbers till "upper_limit",based on current position i is tight bound or not
 and count of ones till now from positions [0...i-1] are "countOnes".
  */
        function<int(int i,int tight,int countOnes)> digit=[&](int i,int tight,int countOnes){
            if(i==upper_limit.size())return countOnes;
            int &ans=dp[i][tight][countOnes];
            if(ans!=-1)return ans;
            
            ans=0;            
            char up=tight?'9':upper_limit[i];
            for(char c='0';c<=up;c++){
                if(c=='1')ans+=digit(i+1,tight|(c!=up),countOnes+1);
                else ans+=digit(i+1,tight|(c!=up),countOnes);
            }
            return ans;
        };
        
        return digit(0,0,0);
    }
};