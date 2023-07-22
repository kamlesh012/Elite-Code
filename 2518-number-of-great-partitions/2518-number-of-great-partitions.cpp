#define ll long long
#define mod 1000000007
class Solution {
public:
    int countPartitions(vector<int>& a, int k) {
        int n=a.size();
        ll sum=accumulate(a.begin(),a.end(),0ll);
        if(sum<(k+k))return 0;
        //Filtering Out Invalid Subsets.
        
        unordered_map<int,unordered_map<int,int>> dp;
        // vector<vector<int>> dp(n+2,vector<int>(k+2,-1));
        function<int(int,int)> rec=[&](int i,int curr){
            if(curr>k)return 0;
            if(i==a.size()){
                if(curr<k)return 1;
                return 0;
            }
            if(!dp[i].count(curr))
            // if(dp[i][curr]==-1);
            {
                int pick=0,notpick=0;
                int add=(curr+a[i])%mod;
                pick=rec(i+1,add);
                notpick=rec(i+1,curr);
                dp[i][curr]=((pick%mod)+(notpick%mod))%mod;
            }
            return dp[i][curr];
        };
        
        int notValid=rec(0,0);  //calculated the subsets with sum<k.
        notValid*=2;            //adding their counter-part subsets as well.(having sum>k but with other half less than k.) (both pairs need to be >=k. so for either pair not meeting this condition ,the other pair will be not counted as well)
        
        int total=1;        //calculating total possible subsets.
        //these total possible subsets are being considered for only one group.
        for(int i=1;i<=n;i++){
            total=(total*2)%mod;       
        }
        //if one group satisfies the conditions then other will automatically follow after removing invalid ones.
        //removing those subsets which have sum less than k.
        //removed those as well which has sum greater than k but their counterpart has sum less than k. did this by multiplying the later by 2.
        int valid=((total-notValid)+mod)%mod;
        return valid;
    }
};