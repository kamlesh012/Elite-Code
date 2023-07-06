class Solution {
public:
    long long int singleNumber(vector<int>& nums) {
        //Need to do using that ultra fast bitwise operation.
        long long int hash[32]={0},ng=0;
        for(long long int i=0;i<nums.size();++i)
        {
            long long int n=nums[i],j=31;
            if(n<0){
                ng++;
                n*=(-1);
                   }
            while(n>0)
            {
                hash[j]+=n%2;
                j--;
                n/=2;
            }
        }
        
        long long int ans=0;
        for(int i=31;i>=0;--i){
            ans+=(1<<(31-i))*(hash[i]%3);
        }
        
        if(ng%3)ans*=-1;
        return ans;
    }
};