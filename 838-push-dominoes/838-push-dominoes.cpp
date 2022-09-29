class Solution {
public:
    string pushDominoes(string d) {
        int n=d.length();
        vector<int>l(n,0),r(n,0);
        
        for(int i=n-1;i>=0;--i){
            if(d[i]=='R')l[i]=-1;
            else if(d[i]=='L')l[i]=1;
            else{
                if(i+1<n && l[i+1]>0)l[i]+=l[i+1]+1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(d[i]=='L')r[i]=-1;
            else if(d[i]=='R')r[i]=1;
            else{
                if(i-1>=0 && r[i-1]>0)r[i]+=r[i-1]+1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(l[i]==r[i]){
                d[i]='.';
            }
            else if(l[i]==-1)d[i]='R';
            else if(r[i]==-1)d[i]='L';
            else if(l[i]==0)d[i]='R';
            else if(r[i]==0)d[i]='L';
            else if(l[i]<r[i])d[i]='L';
            else if(l[i]>r[i])d[i]='R';
        }
        // for(auto i:l)cout<<i<<" ";cout<<endl;
        // for(auto i:r)cout<<i<<" ";cout<<endl;
        
        
        return d;
    }
};
