class Solution {
public:
    int countSubarrays(vector<int>& a, int k) {
        int n=a.size();
        
        int ind=-1;
        for(int i=0;i<n;i++){
            if(a[i]==k)ind=i;
        }
        
        unordered_map<int,int> mp;
        int bal=0;
        //i need to start from ind to include single element
        for(int i=ind;i<n;i++){
            
            if(a[i]>k)bal+=1;
            else if(a[i]<k)bal-=1;
            else if(a[i]==k)bal+=0;
            
            mp[bal]++;
        }
        
        int ans=0;
        bal=0;
        //i need to start from ind to include single element
        for(int i=ind;i>=0;--i){
            
            if(a[i]>k)bal+=1;
            else if(a[i]<k)bal-=1;
            else if(a[i]==k)bal+=0;
            
            ans+=mp[-bal];  //count all odd length subarrays
            
            ans+=mp[-bal+1];    //count even length subarrays
            
        }
        
        return ans;
        
    }
};