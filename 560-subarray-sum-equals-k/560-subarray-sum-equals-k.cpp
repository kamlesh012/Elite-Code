class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //Creating a Prefix Sum Array
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        
        int cnt=0;
        
//Traditional Prefix SUM    -->      TLE
        
        //i is the starting point of a subarray
        //j is the point where our subarray ends
        //so basically we check if difference of j & (i-1)th element==k or not
        //In short we are checking all possible subarrays for sum k;
        
        //         for(int i=0;i<n;i++){
        //             for(int j=i;j<n;j++){
        //                 if((nums[j]-(i-1>=0?nums[i-1]:0))==k)cnt++;        
        //             }
        //         }
        
//Modifying our Traditional Prefix Sum aproach using Map      -->AC
        
        //Now what we will do is for each ending point (j) we will check
        //if an index(i) has already occured in our array such that
        //the subarray in between them sums up to k.
        //Basically  nums[j]-nums[i-1]=k    OR  NOT
        //This is what we were also doing above but here we will store
        //the sum that we will achieve at each step in our map
        //and find currentsum-k in map
        //which means that we are basically checking if we have 
        //encountered an index(i) such that currentsum-k==prefix sum  at i.
        
        unordered_map<int,int> mp;
        
        //Inserting 0 with 1 occurence in our map
        //in case sum is equal to k then sum-k==0
        //which will be not found in map if do not add 0 explicitely.
        // mp[0]=1;
        
        for(int i=0;i<n;i++){
            
            //This if condition is alternative to mp[0]=1 that we did above.
            if(nums[i]==k)cnt++;
            //if prefix sum if k then increase ans by one.
            //but still need to do the below operation
            //to add all the previous occurences/subarrays.
            
            int req=nums[i]-k;
            if(mp.find(req)!=mp.end()){
                //if found add the number of times the 
                //required sum has occured previously
                cnt+=mp[req];
                //we are also storing the occurence of each sum
                //that will be the number of times a given sum has occured
            }

            //add occurence of current sum of map
            //so that it can be found in the future 
            mp[nums[i]]++;
        }
        return cnt;
    }
};