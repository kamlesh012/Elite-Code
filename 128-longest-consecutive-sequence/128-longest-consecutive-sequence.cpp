class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       //O(n)-Striver's Solution.
        
        //The Main Key Observation is that for each element we check if it is the
        //start of a consecutive sequence or not.
        //if not continue.
        //if yes iterate till the end of the sequence to get the length.
        //this saves us from unnecessary iterations as well.
        
        // Check if an element is the starting point of a consecutive sequence or not.
        unordered_set<int> st(nums.begin(),nums.end());
        int longest=0;
        for(auto i:st){
            int prev=i-1,curr=1;
            if(st.find(prev)==st.end()){
                int j=1;
                while(st.find(i+j)!=st.end()){
                    j++;
                    curr++;
                }
                longest=max(longest,curr);
            }
        }
        return longest;
        
    }
};