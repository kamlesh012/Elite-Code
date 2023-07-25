class Solution {
public:
    //I am replacing the current element with it's best place in the current longest increasing subsequence so that i+1 is the length of the longest increasing subsequence whose greatest element is the current element.
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> longest;
        int ans=0;
        //longest[i] represents that the longest increasing subsequence with current element as the end is of length (i+1)[0 based indexing]
        
        //Here WHat we are doing is that  we are greddily building the longest increasing subsequence in longest array.
        
        for(int i=0;i<n;i++){
            //if longest is empty or the last of element of longest is smaller that current element add the current element to longest increasing it's length by on.
            if(longest.empty() || longest.back()<nums[i]){
                longest.push_back(nums[i]);
                //this means that if nums[i] is the last element of longest vector then longest increasing subsequence will be of length (i+1)
            }
            else{
                //here if elements already greater than nums[i] exist in longest that means current element cannot be end of the current longest incresing subsequence but I can be end point of a shorter subsequence which might in future be longest increasing subsequence.
                //so I am finding index of the element that is just smaller than me.
                // & I will place myself just after than element.
                //let that index of element just smaller than me be i.
                //which means that the longest increasing subsequence whose end point I am now,has length (i+1).
                int index=lower_bound(longest.begin(),longest.end(),nums[i])-longest.begin();
                longest[index]=nums[i];
            }
        }
        return longest.size();
    }
//     Dry Run this for intuition 
//     https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Segment-Tree-Solutions-Picture-explain-O(NlogN)
};