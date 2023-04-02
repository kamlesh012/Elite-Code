class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //O(N) solution.
        //Intuition is to place each element at its correct position (i-th)index by swapping 
        //it with the element that is at its position repeatedly until max elements are at their
        //respective positions(i-th).
        //not considering duplicates,non positives,greater than n numbers.
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            //Not considering non positives,numbers greater than n,elements already at their place,elements at whose place the correct element doesn't already lie.
            
            //consider the case [1,1] for last case.
            while(nums[i]>0 && nums[i]<=n && nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};