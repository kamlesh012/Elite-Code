#define mod 1000000007
class Solution {
public:
    // int rec(int n, int minProfit, vector<int>& group, vector<int>& profit,int i)
        
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int totalcrimes=group.size();        
        vector<vector<vector<int>>> dp(totalcrimes+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,0)));
        
       for(int crime=0;crime<=totalcrimes;crime++) {
           
           for(int people=0;people<=n;people++){
               
               for(int curr_profit=0;curr_profit<=minProfit;curr_profit++){
                   //Base Case in Solution:Passing
                   if(!crime && !curr_profit && !people){
                       dp[crime][people][curr_profit]=1;
                   }
                   else if(!crime)continue;
                   
                   //My Base Case:Failing
                   // if(!curr_profit){dp[crime][people][curr_profit]=1;}
                   // else if(crime==0 || people==0){
                   //  continue;        
                   // }
                   
                   else
                   {
                       dp[crime][people][curr_profit]=(dp[crime-1][people][curr_profit]);
                       if(people>=group[crime-1]){
                           
                           if(curr_profit<profit[crime-1]){
                               // dp[crime][people][curr_profit]+=(dp[crime-1][people-group[crime-1]][0])%mod;
                               dp[crime][people][curr_profit]=((dp[crime][people][curr_profit]%mod)+(dp[crime-1][people-group[crime-1]][0])%mod)%mod;
                           }
                           
                           else 
                               dp[crime][people][curr_profit]=((dp[crime][people][curr_profit]%mod)+(dp[crime-1][people-group[crime-1]][curr_profit-profit[crime-1]])%mod)%mod;
                           
                       }
                   }
               }
           }
       }
        int total_ways=0;
        for(int ways=0;ways<=n;ways++){
            total_ways=(total_ways%mod+(dp[group.size()][ways][minProfit])%mod)%mod;
        }
        
        return total_ways;
    }
};