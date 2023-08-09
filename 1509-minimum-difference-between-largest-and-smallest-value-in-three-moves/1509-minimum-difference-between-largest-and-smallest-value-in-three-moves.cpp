class Solution {
public:
    int minDifference(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int ans=INT_MAX;
        if(a.size()<5)return 0;
        
        //Trying out all the possibilities.
        
        ans=min(ans,a[n-4]-a[0]);
        ans=min(ans,a[n-3]-a[1]);
        ans=min(ans,a[n-2]-a[2]);
        ans=min(ans,a[n-1]-a[3]);
        
        return ans;
    }
    
};