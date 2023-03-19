class Solution {
public:
    ///BUT WHY??
    // my multiset solution not working for duplicates [1,1,1] 1. need to debug.
    // int sub(vector<int>&a,multiset<int>&my,int k,int i){
    int sub(vector<int>&a,unordered_map<int,int> &my,int k,int i){
       if(i==a.size()){
           // for(auto x:my)cout<<x<<" ";
           // cout<<endl;
           return 1;
       }
        int pick=0;
        // if(my.find(a[i]+k)==my.end() && my.find(a[i]-k)==my.end()){
        if(!my[a[i]+k]&& !my[a[i]-k]){
            my[a[i]]++;
        // my.insert(a[i]);
        pick=sub(a,my,k,i+1);
            my[a[i]]--;
        // my.erase(a[i]);    
        }
        int notp=sub(a,my,k,i+1);
        return pick+notp;
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> empty;
        // multiset<int> empty;
        int n=nums.size();
        int ans=sub(nums,empty,k,0);
        return ans-1;
        
    }
};