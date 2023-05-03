class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),cnt=0;
        /*
        //Brute Force O(n^3)
        for(int end=0;end<n;end++){
            for(int start=0;start<=end;start++){
                int sum=0;
                for(int ptr=start;ptr<=end;ptr++){
                    sum+=nums[ptr];
                }
                if(sum==k)cnt++;
            }
        }
        */
        
        //Better | Prefix-Sum | O(n^2)
        /*
        vector<int> pre=nums;
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        for(int end=0;end<n;end++){
            for(int start=0;start<=end;start++){
                int prev=0;
                if(start>0)prev=pre[start-1];
                int sum=pre[end]-prev;
                if(sum==k)cnt++;
            }
        }
        
        */
        //Possibly Optimal
        map<int,int> mp;
        mp[0]=1;
        vector<int> pre=nums;
        for(int i=1;i<n;i++){
            pre[i]+=pre[i-1];
        }
        for(int end=0;end<n;end++){
            if(mp[pre[end]-k]){
                cnt+=mp[pre[end]-k];
            }
            mp[pre[end]]++;
        }
        return cnt;
    }
};