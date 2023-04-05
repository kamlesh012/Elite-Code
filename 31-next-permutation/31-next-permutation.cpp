class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        //WHy are we starting from the back?
//         Because we want to longest common prefix ,so that our next permutation is as close
        // to current permutation as possible.
        
        //since a decreasing array is the last permutation & there is not next permuattion 
        //for a decreassing permutation ,we will continue finding the first permutation that is not decreasing.
        
        //as we will find a no. that breaks decreasing permutation order,since it is at rearest end possible, it will be the start of next permutation.
        //now we need to find a value that should be successor of that value, to get the next permutation we will find a value that is just greater than current value among all values after the current value.
        //the nearest greater value to current will be the start of next permutation & all elements of next permutation will be arranged in such a way so that they form the minimal/starting permutation. as we have alread observed a increasingly sorted permutation is the minimal possible.
        // so we will sort the remaining elements.
        
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1])i--;
        
        if(i>=0){
            int mn=INT_MAX,ind=-1,x=i;
            // cout<<mn<<" "<<nums[x]<<endl;
            for(x=i;x<n;x++){
                // cout<<nums[x]<<" "<<mn<<" "<<x<<endl;
                if(nums[x]>nums[i]){
                    if(nums[x]<mn){
                        mn=nums[x];
                               ind=x;}
                              }
            }
            // cout<<nums[i]<<" "<<nums[ind]<<endl;
            // cout<<mn<<" "<<nums[x]<<" "<<x<<endl;
            swap(nums[i],nums[ind]);
        }
        sort(nums.begin()+i+1,nums.end());
    }
};