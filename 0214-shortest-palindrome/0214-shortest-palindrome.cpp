class Solution {
public:
    string shortestPalindrome(string s) {
        int m=s.length();
        string temp=s;
        string original=temp;
        reverse(temp.begin(),temp.end());
        s.push_back('#');
        s+=temp;
        int n=s.length();
        vector<int> lps(n,0);
        int i=1,len=0;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0)len=lps[len-1];
                else i++;
            }
        }
        // cout<<lps[n-1]<<endl;
        len=m-lps[n-1];
        temp=temp.substr(0,len);
        return temp+original;
    }
};