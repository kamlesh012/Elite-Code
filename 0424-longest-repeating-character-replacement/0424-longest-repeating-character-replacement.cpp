class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> mp(26,0);
         for(auto i:s){
             mp[i-'A']++;
         }
        
         function<int(char c)> slide=[&](char c){
          int remove=0,j=0,ans=0;
            for(int i=0;i<s.size();i++){
                if(s[i]!=c)remove++;
                while(j<i && remove>k){
                    if(s[j]!=c)remove--;
                    j++;
                }
                ans=max(ans,i-j+1);
            }
            return ans;
        };
        
        int ans=0,cnt=0;
        for(char c='A';c<='Z';c++){
            if(mp[c-'A']){
                // cnt++;
                ans=max(ans,slide(c));
            }
        }
        cout<<cnt<<" "<<ans<<endl;
        // if(cnt==1)return s.size();
        return ans;
    }
};