class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        vector<int> v(st.begin(),st.end());
        int n=nums.size();
        int ans=n;
        for(int i=0;i<v.size();i++){

            int limit=v[i]+(n-1);
            int ind=upper_bound(v.begin(),v.end(),limit)-v.begin();
            ans=min(ans,i+(n-ind));
        }
        
//             NOTE:
//             if no element grater than searched element is found upper_bound returns container.end()
//              container.end()-container.begin()=length of container;
        return ans;
    }
};