class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int l=0,n=nums.size(),sum=0;
        
        //Add element from right until sum>x
        int r=n-1;
        while(r>=0 && sum<=x){
            sum+=nums[r];
            r--;
        }
        
        //r should point on the first element from the right that is added to sum
        r++;
        
        int len=INT_MAX;
        //both conditions are equal to n as a case where l will cover the whole array is taken into consideration.
        
        while(l<=r && r<=n){
            
            //if sum<x keep adding from left.
            while(l<r && sum<x){
                sum+=nums[l];
                l++;
            }
            
            //update ans if condition is satisfied
            if(sum==x){
                len=min(len,(n-r)+l);
            }
            
            //keep moving backwards &  decrementing the answer
            if(r<n){
                //decrement only if inside the range
                sum-=nums[r];
            }
            
            //this is kept outside the if condition so that r can become n+1 & l can cover the whole array as well.(corner case)
            r++;
        }
        return len==INT_MAX?-1:len;
    }
};