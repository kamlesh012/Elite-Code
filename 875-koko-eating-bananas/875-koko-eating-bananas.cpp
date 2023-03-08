#define ll long long
class Solution {
public:
bool predicate(vector<int> &a,ll h,ll k){
    ll curr=0;
    for(ll i=0;i<a.size();i++){
        curr+=(a[i]-1)/k+1;
        if(curr>h)return false;
    }
    return true;
}
    int minEatingSpeed(vector<int>& wt, int k) {
        ll n=wt.size();
        ll l=0,h=accumulate(wt.begin(),wt.end(),0ll)+1;
        while(h-l>1){
            ll mid=((h-l)/2)+l;
            if(predicate(wt,k,mid))h=mid;
            else l=mid;
        }
        return h;
    }
};