class Solution {
public:
//     https://leetcode.com/problems/remove-boxes/discuss/645838/Evolve-from-intuition-to-dp
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        
        //APPROACH:
        //Remove boxes with same colour as ends(left end here) & try to maintain a streak of boxes that has been removed till now to inculde into answer.
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)
                                                              ));
       function<int(int,int,int)>  rec=[&](int l,int r,int streak){
        if(l>r)return 0;
           if(dp[l][r][streak]==-1){
               
               int curr=(streak+1)*(streak+1)+rec(l+1,r,0); //end current streak
               
               int ans=0;
               //NOW Try over the combination of choosing all possible Boxes of same colour as left end & Continuing the same for other intervals.
               
               for(int i=l+1;i<=r;i++){
                   if(boxes[i]==boxes[l]){
                       int middle_segment=rec(l+1,i-1,0);//This finds the solution for the range l+1 to i-1.Since l+1 does not necessarily have the same colour as i,streak is 0.
                       
                       int next_segment=rec(i,r,streak+1);
                       //This is the next point that has same colour as left end , increase the streak by 1 as current left has same colour as i.
                       
                       ans=max(ans,middle_segment+next_segment);
                   }
               }
               
               dp[l][r][streak]=max(ans,curr);
           }
           return dp[l][r][streak];
       };
        return rec(0,n-1,0);
        
    }
};