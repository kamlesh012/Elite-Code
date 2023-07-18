class Solution {
public:
    
    bool checkPartitioning(string s) {
        int n=s.length();
        vector<vector<bool>> pal(n+1,vector<bool>(n+1));
        //O(n^3) brute force palindrome checker.->TLEd.
//         for(int i=0;i<n;i++){
//             for(int j=i;j<n;j++){
//                 bool ok=true;
//                  int l=i,r=j;
//                   int ans=1;
//                   while(l<=r){
//                       if(s[l++]!=s[r--]){
//                           ok=false;
//                           break;
//                         }
//                   }
//                 pal[i][j]=ok;
//             }
//         }
        
        //Thanks Votrubac for this simple techinque.
        //Precomputing whether a substring is palindrome or not for all substrings
        
        //Efficient appraoch using dp in O(n^2);
        for(int i=n-1;i>=0;--i){
            for(int j=i;j<n;j++){
                pal[i][j]=(s[i]==s[j])?(i+1>=j || pal[i+1][j-1]):false;
            }
        }
        
        //Votrubac's Iterative way to split string into three ways.(faster)AC
        
        for(int i=0;i<n;i++){
            if(pal[0][i]){
                for(int j=i+1;j<n;j++){
                    if(pal[i+1][j] && pal[j+1][n-1])return true;
                }
            }
        }
        return false;
        
        //My Standard DP(slower)AC
        // vector<vector<int>> dp(n+1,vector<int>(10,-1));
        // function<bool(int i,int cnt)> rec=[&](int i,int cnt){
        //     if(i>=n)return !cnt;
        //     if(dp[i][cnt]==-1){
        //         bool ans=false;
        //         for(int j=i;j<n;j++){
        //             if(pal[i][j] && cnt)ans|=rec(j+1,cnt-1);
        //         }
        //         dp[i][cnt]=ans;
        //     }
        //     bool curr=dp[i][cnt];
        //     return curr;
        // };
        // return rec(0,3);
        
    }
};