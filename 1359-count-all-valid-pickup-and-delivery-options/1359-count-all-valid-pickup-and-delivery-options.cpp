class Solution {
public:
    int countOrders(int n) {
        
        int mod=1000000007;
        
        long long pickup=1;
        //no. of ways to arrange pickups.
        for(int i=1;i<=n;i++){
            pickup=(pickup*i)%mod;
        }
//         no. of ways to pickup.
        // from right hand side.
      long long delivery=1;
        for(int i=1;i<2*n;i+=2){
            delivery=(delivery*i)%mod;
        }
        
        return ((pickup%mod)*(delivery%mod))%mod;
    }
};