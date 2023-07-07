class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // nums.push_back(0);
        int l=0,n=nums.size(),sum=0;
        int r=n-1;
        while(r>=0 && sum<=x){
            sum+=nums[r];
            r--;
        }
        r++;
        
        // cout<<sum<<endl;
        // cout<<l<<" start "<<r<<endl;
        int len=INT_MAX;
        // if(sum==)
        while(l<=r && r<=n){
            // while(r<n && sum>x){
            //     sum-=nums[r];
            //     r++;
            // }
            // cout<<"After first sum: "<<sum<<" l "<<l<<" r "<<r<<endl;
            while(l<r && sum<x){
                sum+=nums[l];
                l++;
            }
            // cout<<"After second  sum:"<<sum<<" l "<<l<<" r "<<r<<endl;
            // cout<<sum<<endl;
            // cout<<l<<" "<<r<<endl;
            // cout<<n-r<<" right & left "<<l<<endl;
            if(sum==x){
                // cout<<"Equal "<<sum<<" "<<x<<endl;
                // cout<<"Equal "<<r<<" "<<l<<endl;
                len=min(len,(n-r)+l);
            }
            
            if(r<n){
                sum-=nums[r];
            }
            r++;
        }
        return len==INT_MAX?-1:len;
    }
};