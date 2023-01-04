class Solution {
public:

    long long int lcm( int  a, int  b){
        long long int first= (a/__gcd(a,b));
        return first*b;
    }
    
    int subarrayLCM(vector<int>& nums, int k) {
        
        int n=nums.size(),mx=0;
        for(int i=0;i<n;i++){
            long long c=nums[i];
            for(int j=i;j<n;j++){
                c=lcm(c,nums[j]);
                if(c==k)mx++;
            }
        }
        return mx;
    }
};