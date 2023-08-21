class Solution {
public:
    
    int maximizeTheProfit(int n, vector<vector<int>>& a) {
        
        //An Amazing O(n) DP Solution
        //Thanks Pawan Kumar Giri.
        
        unordered_map<int,vector<pair<int,int>>> range;
        //Storing all offers that start at index i  with their end points & gold coins.
        for(auto i:a){
            range[i[0]].push_back({i[1],i[2]});
        }
        
        vector<int> dp(n,0);
        
        //Now iterating over each house
        for(int i=0;i<n;i++){
            
            //worst case answer will be the answer of previous house.
            if(i)dp[i]=max(dp[i],dp[i-1]);
            
            //for all the offers that start at current index
            for(auto &v:range[i]){
                
                int end=v.first,gold=v.second;
                
    //set dp values for offers that start at current index & finish at end index.
                if(i)dp[end]=max(dp[end],dp[i-1]+gold);
                
                else dp[end]=max(dp[end],gold);
                        
            }
        }
        return dp[n-1];
        
        
        /*
        
        //DP+Binary Search O(nlog(n))
        //Sorting on the basis of starting time, so that we can apply binary search 
        //to find index of the next offer  that has starting time greater than ending time of current offer.
        sort(a.begin(),a.end());
        vector<int> dp(a.size()+1,-1);
        
        //Storing starting point of offers in sorted order so that binary search can be applied on this array to get index of required offer.
        //That same index can be use to access the corresponding offer in 2d vector named a.
        vector<int> start;
        for(auto i:a){
            start.push_back(i[0]);
        }
        
        function<int(int i)> rec=[&](int i){
            if(i>=a.size()) return 0;
            if(dp[i]!=-1) return dp[i];
            
            int nopick=rec(i+1);
            int ind=upper_bound(start.begin(),start.end(),a[i][1])-start.begin();
            int pick=a[i][2]+rec(ind);
            
            return dp[i]=max(pick,nopick);
        };
        
        return rec(0);
        */
    }
};