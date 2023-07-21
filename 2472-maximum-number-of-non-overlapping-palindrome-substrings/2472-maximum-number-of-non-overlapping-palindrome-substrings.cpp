class Solution {
public:
    int maxPalindromes(string s, int k) {
        
        int n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<pair<int,int>> intervals;
        
        //Finding whether each substring is Palindrome or not.in O(n^2)
        //this is a classical  dp problem in itself.(Palindrome Substring on LC)
        for(int i=n-1;i>=0;--i){
            for(int j=i;j<n;j++){
                dp[i][j]=(s[i]==s[j]?i+1>=j || dp[i+1][j-1]:false);
                if(j-i+1>=k && dp[i][j])intervals.push_back({i,j});
            }
        }
        
        //Now finding the min no. of intervals to remove such that the remaining intervals remain non-overalapping.
        //because min intervals to remove = max no. of non overlapping intervals left.
        //Applying the concept of Non-Overlapping Interavls on interval of substrings of size>=k to achieve that.
        
        sort(intervals.begin(),intervals.end(),[&](pair<int,int> &a,pair<int,int> &b){
           if(a.second==b.second) return a.first<b.first;
            return a.second<b.second;
        });
        
        int remove=0;
        int last=-1;
        for(auto i:intervals){
            if(last>=i.first){
                remove++;
            }
            else last=i.second;
        }
        //Max Non overlapping intervals = Total Intervals - Min Overlapping Intervals to remove.
        return intervals.size()-remove;
    }
};