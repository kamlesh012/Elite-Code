class Solution {
public:
     int dp[20][10001];
    
     int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
         //First way is to store the sum of all rods taken.
    //dp[i][j] stores the sum of rods,upto i rods if j is the difference b/w two sets whose sum is stored in dp[i][j];
         
         function<int(int,int)> rec=[&](int i,int diff){
            if(i==n){
                if(diff==0)return 0;
                return -100005;
            }
            int &curr=dp[i][diff+5000];
            if(curr==-1){
        
                int taller=dp[i][diff+5000];
                int shorter=taller-diff;
                
                //not pick
                int np=rec(i+1,diff);
                

                //add to taller
                int tall=rods[i]+rec(i+1,(taller+rods[i])-shorter);
                
                //second way
                // int tall=rods[i]+rec(i+1,(taller+rods[i])-shorter);
                
                //add to shorter
                int small=rods[i]+rec(i+1,taller-(shorter+rods[i]));
                
                //second way
                // int small=rec(i+1,abs(taller-(shorter+rods[i])));
                
                //but don't know how the second way is handling the case when
                //rods[i]>diff
                //this case is being handled iteratively in the third code below.
                
                curr=max(np,(max(tall,small)));
             }
             return curr;
         };
         
        memset(dp,-1,sizeof(dp));
         //dividing by two because dp[i][j] stores the sum of both the towers(all the rods chosen although when they can be divided into two sets of equal sum) 
        return rec(0,0)/2;
         
         //second way
         // return rec(0,0);
    }
   /*
   
   //Here dp[i][j] represents the taller board if out of i rods there difference is j.
   //this method storest the taller of the boards.
   
   int tallestBillboard(vector<int>& rods) {
        int m = rods.size();
        int n = std::accumulate(rods.begin(), rods.end(), 0) + 1;
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
        dp[0][0] = 0;
        dp[0][rods[0]] = rods[0];
        
        for (int i = 1; i < m; i++) {
            int rod_len = rods[i];
            for (int diff = 0; diff < n; diff++) {
                
                // don't include
                int tallest = dp[i-1][diff];
                
                 // subtract from the taller
                if (diff >= rod_len && dp[i-1][diff-rod_len] != -1) {
                    tallest = std::max(tallest, dp[i-1][diff - rod_len] + rod_len);
                }
                if (diff < rod_len && dp[i-1][rod_len - diff] != -1) {
                        //handling the case skipped above
                    tallest = std::max(tallest, dp[i-1][rod_len - diff] + diff);
                }
                
                 // subtract from the shorter
                if (diff + rod_len < n && dp[i-1][diff + rod_len] != -1) {
                    tallest = std::max(tallest, dp[i-1][diff + rod_len]);
                }
                
                dp[i][diff] = tallest;
            }
        }
        
        int max_height = 0;
        for (const auto& l : dp) {
            max_height = std::max(max_height, l[0]);
        }
        
        return max_height;
    }
    */
};