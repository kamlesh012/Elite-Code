#define ll long long
class NumArray {
public:
    vector<int> st;
    vector<int> a;
    void build(ll tidx,ll s,ll e){
        // cout<<s<<" base case "<<e<<endl;
        // cout<<tidx<<endl;
        if(s==e){
            st[tidx]=a[s];
            return;
            }
        
        ll mid=(s+e)/2;
        build(2*tidx,s,mid);
        build((2*tidx)+1,mid+1,e);
        
        st[tidx]=st[2*tidx]+st[(2*tidx)+1];
        
    }
    void upd(ll tidx,ll i,ll val,ll s,ll e){
        if(s==e && s==i){
            st[tidx]=val;
            return;
        }
        ll mid=(s+e)/2;
        if(i<=mid)upd(2*tidx,i,val,s,mid);
        else upd((2*tidx)+1,i,val,mid+1,e);
        
        st[tidx]=st[2*tidx]+st[(2*tidx)+1];
    }
    int query(ll tidx,ll l,ll r,ll s,ll e){
        //disjoint
        if(s>r || l>e)return 0;
        //total
        if(s>=l && e<=r)return st[tidx];
        //partial
        ll mid=(s+e)/2;
        int left=query(2*tidx,l,r,s,mid);
        int right=query(2*tidx+1,l,r,mid+1,e);
        return left+right;
    }
    
    NumArray(vector<int>& nums) {
        a=nums;
        int n=nums.size();
        st.resize(4*n,0);
        build(1,0,n-1);
        
    }
    
    void update(int index, int val) {
        upd(1,index,val,0,a.size()-1);
    }
    
    int sumRange(int left, int right) {
        return query(1,left,right,0,a.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */