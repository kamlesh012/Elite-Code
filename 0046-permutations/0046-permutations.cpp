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
    
    //Stores the answer
    vector<vector<int>> master;
    
    //Stores which elements have been added to current permutation.
    unordered_set<int> st;
    
    void solve(vector<int> &temp,vector<int> &nums){
        
        if(temp.size()==nums.size()){
            master.push_back(temp);
            return;
        }
        
        //Do this for all possible elements
        for(int i=0;i<nums.size();i++){
            
            if(st.find(nums[i])==st.end()){
                
                // 1->Insert    
                st.insert(nums[i]);
                temp.push_back(nums[i]);
                
                // 2->Explore
                solve(temp,nums);
                
                // 3->Revert
                st.erase(nums[i]);
                temp.pop_back();
                
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        //STandard Approach
        vector<int> tmep;
        solve(tmep,nums);
        return master;
        
        //         My Non-STandard Approach Using Next Permutation
        /*
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
        */
    }
};