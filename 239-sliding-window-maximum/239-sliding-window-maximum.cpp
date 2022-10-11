class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //
        deque<int> dq;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            //remove out of window elements
             if(!dq.empty() && dq.front()<=i-k)dq.pop_front();
            
            //Keep removing elements from the end that are smaller than
            //current element because we only need the max, in latest window
            while(!dq.empty() && nums[dq.back()]<nums[i])dq.pop_back();
            
            //push index of current element
            dq.push_back(i);
                
            //add max of the current window to answer.
            if(i>=k-1)ans.push_back(nums[dq.front()]);
        }
        
     return ans;   
    }
};