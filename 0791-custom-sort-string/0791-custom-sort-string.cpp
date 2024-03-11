class Solution {
public:
    string customSortString(string order, string s) {
       int n=order.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[order[i]]=i;
        }
        int cnt=0;
        for(auto i:s){
            if(mp.find(i)==mp.end()){
                mp[i]=n+cnt;
                cnt++;
            }
        }
        sort(s.begin(),s.end(),[&](char a,char b){
           return mp[a]<mp[b] ;
        });
        return s;
    }
};