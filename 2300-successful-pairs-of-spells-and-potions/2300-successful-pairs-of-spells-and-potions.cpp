class Solution {
public:
    vector<int> successfulPairs(vector<int>& spl, vector<int>& ptn, long long x) {
        long long n=spl.size();
        long long m=ptn.size();
        sort(ptn.begin(),ptn.end());
        vector<int> ans;
        
        for(long long i=0;i<n;i++){
            long long fn=((x-1ll)/spl[i])+1ll;
            auto it=lower_bound(ptn.begin(),ptn.end(),fn);
            if(it==ptn.end()){ans.push_back(0ll);continue;}
            long long index=ptn.end()-it;
            ans.push_back(index);
        }
        return ans;
        
    }
};