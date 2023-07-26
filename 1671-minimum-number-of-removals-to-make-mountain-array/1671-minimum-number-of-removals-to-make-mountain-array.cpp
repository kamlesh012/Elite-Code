class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        
        int n=a.size();
        int ans=n;
        
        vector<int> lis(n+1,1),lds(n+1,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    lis[i]=max(lis[i],lis[j]+1);
                }
            }
        }
        
        for(int i=n-2;i>=0;--i){
            for(int j=n-1;j>=i;--j){
                if(a[j]<a[i]){
                    lds[i]=max(lds[i],lds[j]+1);
                }
            }
        }
        // for(auto i:lds)cout<<i<<" ";
        // cout<<endl;
        //Tricky Test Case:[9,8,1,7,6,5,4,3,2,1]
        // [100,92,89,77,74,66,64,66,64]
        //LIS needs to have min length 3.
        for(int i=0;i<n;i++){
            // cout<<lis[i]<<" "<<lds[i]<<endl;
            if(lis[i]>1 && lds[i]>1){
                int add=lis[i]+lds[i]-1;
                int res=n-(add);
                // cout<<"Current ans: "<<res<<endl;
                ans=min(ans,res);    
            }
        }
        // cout<<endl;
        return ans;
    }
};