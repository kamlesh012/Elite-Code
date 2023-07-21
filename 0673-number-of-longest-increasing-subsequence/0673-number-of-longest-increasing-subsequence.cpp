class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis(n+1,1),cnt(n+1,1);
        //lis stores the length of longest increasing subsequence.
        //cnt stores the number of longest increasing subsequences at index i.
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(lis[j]+1>lis[i]){
                        //new lis
                        lis[i]=lis[j]+1;
                        //my cnt will be useless as my cnt stores subsequences with smaller lis.
                        //we have found longer/new lis so the cnt of that longer lis will be stored now.
                        
                        cnt[i]=cnt[j];
                    }
                    else if(lis[j]+1==lis[i]){
                        //add existing subsequences that can form more lis of max lengths to ans as well
                        cnt[i]+=cnt[j];                 
                    }
                }
            }
        }
        
        int mxt=*max_element(lis.begin(),lis.end());
        int ans=0;
        for(int i=0;i<n;i++){
            if(lis[i]==mxt)ans+=cnt[i];
        }
        return ans;
    }
};