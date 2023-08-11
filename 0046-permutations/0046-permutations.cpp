class Solution {
public:
    vector<int> next_perm(vector<int> &a){
        
        int n=a.size();
        if(n==1)return a;
        int i=n-2;
        while(i && a[i]>a[i+1])i--;
        int curr=a[i];
        int j=n-1,last=INT_MAX;
        int ind=j;
        
        while(j>i){
            if(a[j]>curr && last>a[j]){
                last=a[j];
                ind=j;
            }
            j--;
        }
        swap(a[i],a[ind]);
        sort(a.begin()+i+1,a.end());
        
        return a;
    }
    
    int fact(int n){
        int ans=1;
        for(int i=2;i<=n;i++){
            ans*=i;
        }
        return ans;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>> ans;
        int sz=fact(n);
        vector<int> curr=nums;
        sort(curr.begin(),curr.end());
        for(int i=0;i<sz;i++){
            vector<int> temp=next_perm(curr);
            ans.push_back(temp);
            temp=curr;
        }
        return ans;
    }
};