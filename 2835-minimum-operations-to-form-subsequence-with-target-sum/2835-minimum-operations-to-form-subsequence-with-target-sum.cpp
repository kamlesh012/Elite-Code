class Solution {
public:
    int minOperations(vector<int>& v, int target) {
        
        int n=v.size();
        long long total_sum=accumulate(v.begin(),v.end(),0ll);
        if(total_sum<target)return -1;
        
        sort(v.begin(),v.end());
        
        //Sample Test Case: (Iterate from right towards left)
        //1 2 4 8 16       target =13
        
        //skip 16, take 8 & 4     now target=1
        //skip 2,  take 1.      
        
        //0 Operations Required.
        
        int i=n-1,ops=0;
        while(target>0){
            int curr=v.back();
            v.pop_back();

            long long remaining_sum=total_sum-curr;
            if(remaining_sum>=target){
                total_sum-=curr;
            }
            else if(curr<=target){
                total_sum-=curr;
                target-=curr;
            }
            else{
                v.push_back(curr/2);
                v.push_back(curr/2);
                ops++;
            }
        }
        
        return ops;
    }
};