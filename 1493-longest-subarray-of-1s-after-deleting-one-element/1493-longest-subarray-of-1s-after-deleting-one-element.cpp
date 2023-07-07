class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        vector<pair<int,int>> ind;
        int start=-1,end=-1,mxseq=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                 if(start==-1)start=i;
                end=i;
            }
            else if(start!=-1){
                ind.push_back({start,end});
                mxseq=max(mxseq,end-start+1);
                start=-1;
                end=-1;
            }
        }
        
        if(nums[n-1]==1){
            ind.push_back({start,end});
            mxseq=max(mxseq,end-start+1);
        }
        
        // for(auto i:ind){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        int ans=0;
        for(int i=1;i<ind.size();i++){
            if((ind[i].first-ind[i-1].second)==2){
                ans=max(ans,ind[i].second-ind[i-1].first);
            }
        }
        
        if(ind.empty())ans=0;
        else if(mxseq==n)ans=mxseq-1;
        else if(!ans)ans=mxseq;
        else ans=max(ans,mxseq);
        
        return ans;
        
    }
};