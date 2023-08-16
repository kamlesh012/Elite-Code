class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& rq) {
        
        function<int(int i,vector<int> & freq)> rec=[&](int i,vector<int> &freq){
            if(i==rq.size()){
                for(auto i:freq){
                    if(i)return INT_MIN;
                }
                return 0;
            }
            
            int pick=0,notpick=0;
            notpick=rec(i+1,freq);
            
            freq[rq[i][0]]--;
            freq[rq[i][1]]++;
            pick=1+rec(i+1,freq);
            
            freq[rq[i][0]]++;
            freq[rq[i][1]]--;
                
            return max(pick,notpick);
        };
        
        vector<int> freq(n,0);
        return rec(0,freq);
    }
};