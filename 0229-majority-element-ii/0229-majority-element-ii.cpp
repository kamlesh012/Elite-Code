class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //the curx of this problem is that
        //at a point the count of majority elemnts will be equal to the count of all other
        //minority elements.
        //after that point count of majoriy elements will exceed.
        //so the majority element will have a greater count.
        
        int cnt1=0,cnt2=0;
        int ele1=INT_MIN,ele2=INT_MIN,n=nums.size();
        
        for(int i=0;i<n;i++){
            if(!cnt1 && nums[i]!=ele2){
                cnt1=1;
                ele1=nums[i];
            }
            else if(!cnt2 && nums[i]!=ele1){
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)cnt1++;
            else if(nums[i]==ele2)cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        // cout<<endl;
        // cout<<cnt1<<" "<<cnt2<<endl;
        // cout<<ele1<<" "<<ele2<<endl;
        // cout<<endl;
        
        vector<int> ans;
        //need to check when cnt1==cnt2, then value of both of them would be zero or less than that.
//         cnt would be wrong but ele1 & ele2 will store correct elements.
        cnt1=0,cnt2=0;
        for(auto i:nums){
            if(i==ele1)cnt1++;
            else if(i==ele2)cnt2++;
        }
        
        if(cnt1>(n/3))ans.push_back(ele1);
        if(cnt2>(n/3))ans.push_back(ele2);
        
        return ans;
        
    }
};