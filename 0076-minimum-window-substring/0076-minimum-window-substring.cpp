class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),m=t.length();
        int i=0,j=0;
        map<char,int> req,got;
        for(auto i:t)req[i]++;
        int cnt=0,min_len=n,start=-1;
        while(i<n){
            if(cnt<m){
                if(req.count(s[i]) && got[s[i]]<req[s[i]])cnt++;
                got[s[i]]++;
            }
            
        // else{
            while(cnt==m){
                if((i-j)<min_len){
                    min_len=i-j;
                    start=j;
                }
                if(req.count(s[j]) && got[s[j]]<=req[s[j]])cnt--;
                got[s[j]]--;
                j++;
            }
        // }
            
            i++;
        }
        if(start==-1)return string();
        return s.substr(start,min_len+1);
        
    }
};