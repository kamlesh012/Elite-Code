class Solution {
public:
    int calculate(long long n, long long m, int cnt){
        int mod=1e9+7;
        long long x=(n*(n+1)/2);
        long long y=(m*(m+1)/2);
        return ((x-y)*cnt)%mod;
    }
    
    int maxProfit(vector<int>& nums, int orders) {
        int n=nums.size();
        long long cost=0;
        priority_queue<pair<long long,long long>> pq;
        sort(nums.begin(),nums.end());
        int mod=1e9+7;
        //Inserting on PQ with frequency.Map could also be used.
        long long prev=nums[0],cnt=1;
        for(int i=1;i<n;i++){
            if(prev==nums[i]){
                cnt++;
            }else{
                pq.push({prev,cnt});
                prev=nums[i];
                cnt=1;
            }
        }
        pq.push({prev,cnt});
        
        //Clever thing to do. to handle the cases where pq has only one element left.
        pq.push({0,0});
        
        while(pq.size()>1){
            
            pair<long,long> top=pq.top();
            pq.pop();
            //no need to worry of RE now, as we've already push 0,0 to pq.
            pair<long,long> second_top=pq.top();
            pq.pop();
            
            long long cnt=(long long)(top.first-second_top.first)*top.second;
            if(cnt>=orders){
                //This is the part in which I was stuck for a long time.
                long long x=orders/top.second,y=orders%top.second;
                
                if(x!=0){
                    
                    cost+=calculate(top.first,top.first-x,top.second)%mod;
                    
                    if(y!=0)cost+=((top.first-x)*y)%mod;
                    
                }
                else{
                    cost+=(top.first*y)%mod;
                }
                
                return cost%mod;
            }
            else{
                cost+=calculate(top.first,second_top.first,top.second)%mod;
                orders-=cnt;
                pq.push({second_top.first,top.second+second_top.second});
            }
        }
        
        return cost%mod;
    }
};