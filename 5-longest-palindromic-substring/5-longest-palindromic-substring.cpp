class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(),mx=0,cnt=0;
        string ans;
        for(int i=0;i<n;i++){
            int l=i-1,r=i+1,curr=1;
            if(s[i]==s[i+1])
            {
                //Even Length Palidrome
                int rr=r+1,currr=curr+1,ll=l;
                while(ll>=0 && rr<=n && s[ll]==s[rr]){
                    ll--;
                    rr++;
                    currr+=2;
                }
                if(currr>mx){
                    ans.clear();
                    for(int x=ll+1;x<rr;x++){
                        ans.push_back(s[x]);
                    }
                    mx=currr;
                }
            }
            //Odd Length Palindrome.
            while(l>=0 && r<=n && s[l]==s[r]){
                l--;
                r++;
                curr+=2;
            }
            if(curr>mx){
                ans.clear();
                for(int x=l+1;x<r;x++){
                    ans.push_back(s[x]);
                }
                mx=curr;
            }
        }
        return ans;
    }
};