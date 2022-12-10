class Solution {
public:
    //couldn't solve during contest.
    //Went in different directions first,later got some observations
    //but wasn't  able  to solve
    int maxJump(vector<int>& stones) {        
        //Odd Even Rule/    Skip
        
        //Claim1:- It is optimal to include all stones in any one of the paths.
        
        //Claim2:- It is not optimal to choose two consecutive stones (i & (i+1))
        //as choosing consecutive stones will increase the distance while returning.
        
        // dist((i-1)&(i+2))> dist((i)&(i+2)) (since array is sorted)
        //it would be best to choose a stone & skip one for returning 
        //to maintain the maximum length of a jump for going as well as coming.
        
        int n=stones.size();
        int cost=stones[1]-stones[0];
        //odd path
        for(int i=3;i<n;i+=2){
            cost=max(cost,stones[i]-stones[i-2]);
        }
        
        //even path
        for(int i=2;i<n;i+=2){
            cost=max(cost,stones[i]-stones[i-2]);
        }
        
//         for(int i=0;i<n;i+=2){
//             if(i<n && i!=n-1 && i+2>=n)cost=max(cost,stones[n-1]-stones[i]);
//             else cost=max(cost,stones[i]-stones[i-1]);
//         }
        
        return cost;
        
        
        
        
        
    }
    //for better explanation
    //https://leetcode.com/problems/frog-jump-ii/discuss/2897888/It's-Greedy-(Even-and-Odd)
};