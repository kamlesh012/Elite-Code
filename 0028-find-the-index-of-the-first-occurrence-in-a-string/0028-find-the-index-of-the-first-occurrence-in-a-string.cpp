class Solution {
public:
    int strStr(string a, string b) {
        int n=a.length(),m=b.length();
        vector<int> lps(m,0);
        
        int i=1,len=0;
        while(i<m){
            if(b[i]==b[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len>0){
                    len=lps[len-1];
                }
                else {
                    lps[i]=0;
                    i++;
                }
            }
        }
        int l=0,r=0;
        while(l<n){
            if(a[l]==b[r]){
                l++;
                r++;
            }
            if(r==m){
                return l-r;
            }
            if(a[l]!=b[r]){
                if(r>0){
                    r=lps[r-1];
                }
                else l++;
            }
        }
        return -1;
    }
    
};