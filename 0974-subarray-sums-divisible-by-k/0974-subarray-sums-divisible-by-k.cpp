class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        //WHy SLIding window won't work to find subarray divisible by k?
//       consider k=5 & array=[1,1,1,1,1,1,1,1];
        
        //now accoring to traditional sliding window, we can find a subaray whose sum==k
        //but not a subarray whose sum is divisible by k as many subarrays satisfying the condition might overlap & there's not a specific condition when to contract our window.
        //Dry run on above test case to understand better.
        
        //So now what? Try Brute force
        //Using Prefix sum find the sum of all possible subarrays 
        //& increase count if any of there sum%k==0;
        //that would be O(n^2);
        
        //Can we do better? Yes!/
        //Explanation:
        /*
        // The problem now boils down to finding the number of pairs i,j whose sum from nums[j] to nums[i] is divisible by k. in better than O(n^2) complexity.
        
        //Now to get the sum of subarrays quickly we will use prefix sums here as well.
        //But we will also use Math to reduce the time complexity.
        
         See a no. A can be expressed as A=B*q+r;
         where A is dividend,B is divisor,q is quotient & r is remainder.
         
         Now in our prefix sum array, suppose we divide prefixsum[i] by k 
         then prefixsum[i] could also be expressed as:
         prefixsum[i]=K*quotienti+remainderi
         
         Similary prefixsum[j] when divided by K can be expressed as:
         prefixsum[j]=K*quotientj+remainderj
         
        //Now to get sum of elements b/w j+1 & i, using prefix sum we do:
        prefixsum[i]-prefixsum[j];
        
        That equation when expanded using the a=(b*q)+r formula becomes:
        prefixsum[i]-prefixsum[j]=(K*quotienti+remainderi) - (K*quotientj+remainderj);
        
        Solving further:
        prefixsum[i]-prefixsum[j]=K*(quotienti-quotientj)+remainderi-remainderj;
        
        here K*(quotienti-quotientj) is a multiple of K,so it is divisble by K.
        
        for the whole expression to be divisible by k remainderi-remainderj must also be divisible by k.
    For remainderi-remainder to be divisible by K it should follow:
    
    remainderi-remainderj=C*k       (where C is some constant )
    
    Solving further we get
    
    remainderi=(C*k)+remainderj
    
    //Now since remainderi & remainderj are remainders of prefixsum[i] & prefixsum[j] when divided by k respectively, so there values must be between 0 & k-1.
    //So for remainderi to be smaller than k, Value of C on RHS must be 0.
    //Only then the expression will be valid.
    & will result in giving :
    
    remainderi=remainderj.
    
    Now this means in the initial equation 
    
    prefixsum[i]-prefixsum[j]=K*(quotienti-quotiendj)+(remainderi-remainderj);
    
prefixsum[i]-prefixsum[j] will be divisble by K when both remainders will be equal.
//That means all the subarrays that has equal remainder %k will have sum divisible by k between them.

Now  again we can't iterate over all pairs i,j to check their where their remainders are equal or not. 
Instead we will use a map and keep a track of remainders we have encountered till now & if current remainder is encountered already that means the subarray in between is divisble by k. 
this will be similar to solving two-sum problem using hashmap
*/
        int n=nums.size();
        vector<int> mp(k,0);
        int ans=0,sum=0;
        mp[0]=1;    //marking for the subarray whose sum==k; 
        
        for(int i=0;i<n;i++){
            // +k for handling negative values,won't affect positive values.
            sum=(sum%k+nums[i]%k +k )%k;
            ans+=mp[sum];//add to answer the number of subarrays that has the same remainder as the current sum.
            mp[sum]++;   //include current to answer.
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    }
};