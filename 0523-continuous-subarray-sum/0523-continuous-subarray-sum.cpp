class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        
        //Editorialist's Better Approach.
        
        //hashmap<sum%k,index>
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]%k==0)return true;
            else if(mp.count(nums[i]%k)==0){
                mp[nums[i]%k]=i;
            }
            else if(mp[nums[i]%k]<i-1)return true;
        }
        return false;
        
        /*
//         MY Approach: check %k till current index but don't add previos index.

        int prev=nums[0]%k;
        for(int i=1;i<n;i++){
        //in case if current element is divisible return true.
        //since i>0 size is already >0.
            if(nums[i]%k==0)return true;
            
            if(mp[nums[i]%k]){
                return true;
            }
            //now add previous to answer.
            mp[prev]++;
            
            //the current one become previous now.
            prev=nums[i]%k;
        }
        return false;
        */
    }
};