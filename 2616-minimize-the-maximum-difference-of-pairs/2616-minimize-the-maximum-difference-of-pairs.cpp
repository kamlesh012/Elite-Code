class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=-1,h=nums.back();
        while(h-l>1){
            long long mid=(h-l)/2+l;
            int cnt=0;
            for(int i=1;i<n;i++){
                if(nums[i]-nums[i-1]<=mid){
                    cnt++;
                    i++;
                }
            }
            if(cnt<p)l=mid;
            else h=mid;
        }
        return h;
    }
};