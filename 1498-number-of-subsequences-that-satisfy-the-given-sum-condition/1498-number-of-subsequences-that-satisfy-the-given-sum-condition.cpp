#define mod 1000000007
long long moduloexpo(int a, int b, int m) {
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
            long long temp=1ll;
            if(nums[l]+nums[r]<=target){
                
                int len=r-l;
                
                //Method 1: 
                //Left Shifting.
                // temp=(1ll<<(r-l))%mod;
                // Wrong Answer.
                //Can't do more than 63 left shifts.
                //modulo is also not  taken carefully.
                
                
                //Method 2: 
                // for(int x=l;x<r;x++){
                //     temp=((temp%mod)*(2%mod))%mod;
                // }
                // Time Limit Exceeded.//might go O(n) in worst case.
                
                //Method 3:
                temp=moduloexpo(2,len,mod);
                //Accepted
                
                ans=(ans%mod+temp%mod)%mod;
                l++;
            }
            else r--;
        }
        return ans;
    }
};