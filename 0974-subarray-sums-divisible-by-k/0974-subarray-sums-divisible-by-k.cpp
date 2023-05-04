class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        int sum=0;
        //I was doing mistake in Modulo Arithmetic.
        
        int ans=0;
        
        mp[0]=1;//edge case to count complete subarray till this index.
        
        for(int i=0;i<n;i++){
            sum=(sum%k+(nums[i]%k))%k;
            //Need to do +k to calculate remainders of negative numbers.
            ans+=mp[(sum+k)%k];
            mp[(sum+k)%k]++;
        }
        
   //Bad Implementation     
        // for(auto i:mp){
            // // if(i.first==0){
            //     int cnt=i.second;
            //     ans+=(cnt*(cnt+1))/2;
            // // }
            // else if(i.second>1){
            // int cnt=i.second;
            // ans+=(cnt*(cnt-1))/2;
            // }
        // }
        return ans;
    }
};