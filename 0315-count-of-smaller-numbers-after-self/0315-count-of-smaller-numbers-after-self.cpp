#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// set -> less, greater , multiset -> less_equal , greater_equal
// // pbds.order_of_key (k) : Number of items strictly smaller than k.
//*pbds.find_by_order(k) : K-th element in a set (cnting from zero).

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        pbds st;
        for(int i=n-1;i>=0;--i){
            int less=st.order_of_key(nums[i]);
            ans[i]=less;
            st.insert(nums[i]);
        }
        return ans;
    }
};