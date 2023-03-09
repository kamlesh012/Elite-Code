class Solution {
public:
    bool predicate(vector<int>&b,int m,int k,int days){
        int mx=INT_MIN;
        int splits=0,n=b.size();
        for(int i=0;i<=n-k;){
            bool ok=false;
            int j=i;
            // cout<<i<<" Start "<<j<<endl;
            for(;j<n && j-i<k;j++){
                // cout<<" Inside:"<<i<<" "<<j<<endl;
                // cout<<" Inside:"<<b[i]<<" "<<b[j]<<endl;
                if(b[j]>days){
                            // i=j+1;
                            // ok=true;
                            break;
                }
            }
            
            // cout<<i<<" End "<<j<<endl;
            if(j-i==k){
                i=j;
                splits++;
            }
            else i=j+1;
            // cout<<"Splits: "<<splits<<endl;
            // if(!ok){i=j;splits++;}
        }
        // cout<<splits<<endl;
        return splits>=m;
    }
    
    int minDays(vector<int>& b, int m, int k) {
        int l=-1,h=*max_element(b.begin(),b.end())+1;
        int oh=h;
        while(h-l>1){
            int mid=(h-l)/2+l;
            if(predicate(b,m,k,mid))h=mid;
            else l=mid;
        }
        if(h>=oh)h=-1;
        return h;
    }
};