class Solution {
public:
    string largestGoodInteger(string num) {
     int n=num.length();
        string ans="";
        for(int i=0;i<=n-3;i++){
            string curr=num.substr(i,3);
            if(curr[0]==curr[1] && curr[1]==curr[2]){
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};