class Solution {
public:
    long long maximumTripletValue(vector<int>& a) {
        
        int n=a.size();
        vector<int> mxl(n,0),mxr(n,0);
        
        long long ans=0;
        mxl[0]=a[0];
        mxr[n-1]=a[n-1];
        
        for(int i=1;i<n;i++){
            mxl[i]=max(mxl[i-1],a[i]);
        }
        
        for(int i=n-2;i>=0;--i){
            mxr[i]=max(mxr[i+1],a[i]);
        }
        
//         for(auto i:mxl){
//             cout<<i<<" ";
//         }
//         cout<<endl;
        
//         for(auto i:mxr){
//             cout<<i<<" ";
//         }
//         cout<<endl;
        for(int i=1;i<n-1;i++){
            long long curr=(mxl[i-1]-a[i])*(1ll*mxr[i+1]);
            // cout<<curr<<endl;
            ans=max(ans,curr);
        }
        
        return ans;
    }
};