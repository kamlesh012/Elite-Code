class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int n=nums.size();
        int l=0,r=0;
        multiset<int> mst;
        long long ans=0;
        while(r<n){
            // // cout<<"Before Left "<<l<<" Right "<<r<<endl;
            // if(mst.size()){
                // cout<<*(mst.rbegin())<<" Before "<<*(mst.begin())<<endl;
                // cout<<"Left "<<l<<" Right "<<r<<endl;
            // }
            mst.insert(nums[r]);
            while(((*mst.rbegin())-(*mst.begin()))>2){
                // cout<<"L before "<<l<<" "<<nums[l]<<endl;
                mst.erase(mst.find(nums[l]));
                l++;
                // cout<<"L after"<<l<<" "<<nums[l]<<endl;
            }
            // if(mst.size()){
            //     cout<<*(mst.rbegin())<<" After "<<*(mst.begin())<<endl;
            // }
                // cout<<"AFter Left "<<l<<" Right "<<r<<endl;
            
            // if(mst.size())
            ans+=(r-l+1);
            // cout<<"Curr Range Diff "<<r-l+1<<" Ans "<<ans<<endl;
            r++;
        }
        
        return ans;
        
        
    }
};