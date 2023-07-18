class Solution {
public:
    
    bool checkPartitioning(string s) {
        int n=s.length();
        vector<vector<bool>> pal(n+1,vector<bool>(n+1));
        
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
        //   for(int i=n-1;i>=0;--i){
        //     for(int j=i;j>=0;--j){
        //         pal[j][i]=(s[i]==s[j])?(j+1>=i || pal[j+1][i-1]):false;
        //     }
        // }
        
//         for(int end=n-1;end>=0;--end){
//             for(int start=end;start>=0;--start){
                
//                 // pal[start][end]=(s[start]==s[end])?(start+1>=end || pal[start+1][end-1]):false;
//                 bool ok=false;
//                 if(s[start]==s[end]){
//                     if(start==end)ok=true;
//                     else if(start+1>=end || pal[start+1][end-1]==true)ok=true;
//                 }
//                 pal[start][end]=ok;
                
//                 if(start+1<=end){
//                 cout<<start+1<<" between "<<end-1<<endl;
//                 cout<<pal[start+1][end-1]<<endl;
//                 }
//                 cout<<start<<" "<<end<<endl;
//                 cout<<s.substr(start,end-start+1)<<endl;
//                 cout<<pal[start][end]<<endl;
//             }
//         }
        
        for(int i=0;i<n;i++){
            // cout<<s.substr(0,i+1)<<endl;
            // cout<<pal[0][i]<<endl;
            if(pal[0][i]){
                for(int j=i+1;j<n;j++){
                    // cout<<s.substr(i+1,j-i)<<" "<<s.substr(j+1,n-j)<<endl;
                    // cout<<i+1<<"-"<<j<<" ----- "<<j+1<<"-"<<n-1<<endl;
                    // cout<<pal[i+1][j]<<" "<<pal[j+1][n-1]<<endl;
                    if(pal[i+1][j] && pal[j+1][n-1])return true;
                }
            }
        }
        return false;
        
        //My DP-TLEing.
//         vector<vector<int>> dp(n+1,vector<int>(10,-1));
        
//         function<bool(int i,int cnt)> rec=[&](int i,int cnt){
//             if(i>=n)return !cnt;
//             if(dp[i][cnt]==-1){
//                 bool ans=false;
//                 for(int j=i;j<n;j++){
//                     if(pal[i][j] && cnt)ans|=rec(j+1,cnt-1);
//                 }
//                 dp[i][cnt]=ans;
//             }
//             bool curr=dp[i][cnt];
//             return curr;
//         };
//         return rec(0,3);
        
    }
};