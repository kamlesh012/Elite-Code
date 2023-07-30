#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, greater_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// set -> less, greater , multiset -> less_equal , greater_equal
// // pbds.order_of_key (k) : Number of items strictly smaller than k.
//*pbds.find_by_order(k) : K-th element in a set (cnting from zero).
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        pbds st;
        
        int n=nums.size();
        st.insert(nums[0]);
        long long ans=0ll;
        
        for(int i=1;i<n;i++){
            long long curr=(nums[i]);
            curr*=2ll;
            
            long long cnt=st.order_of_key(curr);
            
            ans+=cnt;
            st.insert(nums[i]);
        }
        return ans;
    }
};