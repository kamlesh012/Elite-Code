class Solution {
public:
//     Non-Standard Approach Manula Next-Permutation FUnciton.
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
    /*    
        //Standard BackTracking Approach-1
        
         //Stores the answer
        vector<vector<int>> master;
    
    //Stores which elements have been added to current permutation.
        unordered_set<int> st;
        
    function<void(vector<int> &temp)> solve=[&](vector<int> &temp){
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
                    solve(temp);

                    // 3->Revert
                    st.erase(nums[i]);
                    temp.pop_back();

                }
            }

        };
        
        vector<int> temp;
        solve(temp);
        return master;
     */
        vector<vector<int>> ans;
        
        //Standard BackTracking Approach-2
        //Here in this approach we will swap each element of nums with a specific index (say ind) once & in next recursive call we will start from the index ind+1 so that we don't swap back the values we swapped in previous recursive call.
        
        function<void(int ind)> rec=[&](int ind){
            if(ind==nums.size()){
                ans.push_back(nums);
                return;
            }
            //Remember to start i from ind always so that we don't swap values back
            for(int i=ind;i<nums.size();i++){
                swap(nums[i],nums[ind]);
                rec(ind+1);
                swap(nums[i],nums[ind]);
            }
        };
        rec(0);
        return ans;
        
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