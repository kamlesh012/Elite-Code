#define mod 1000000007
long long expo(int a, int b, int m) {
    long long ta=a,tb=b;
    long long res = 1ll; 
         while (tb > 0) {
             if (tb & 1)
                 res = (res*ta) % m;
             ta = (ta * ta) % m;
             tb = tb >> 1ll;
         } 
         return res;
}

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int temp=1;
            if(nums[l]+nums[r]<=target){
                int len=r-l;
                temp=expo(2,len,mod);
                // for(int x=l;x<r;x++){
                //     temp=((temp%mod)*(2%mod))%mod;
                // }
                // temp=(1<<(r-l))%mod;
                ans=(ans%mod+temp%mod)%mod;
                l++;
            }
            else r--;
        }
        return ans;
    }
};