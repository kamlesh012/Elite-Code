class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        long long ans=0,extra=0,total=0;
        vector<int> top;
        sort(bat.rbegin(),bat.rend());
        for(int i=0;i<bat.size();i++){
            total+=bat[i];
            if(i<n)top.push_back(bat[i]);
            else extra+=bat[i];
        }
        // sort(top.begin(),top.end());
        long long l=-1ll,h=total+1ll;
        while(h-l>1){
            long long mid=(h-l)/2+l;
            // cout<<"mid "<<mid<<" l "<<l<<" h "<<h<<endl;
            long long left=0ll;
            
            // cout<<"TOP "<<endl;
            for(auto i:top){
                // cout<<i<<" ";
                left+=max(0ll,mid-i);
            }
            // cout<<endl;
            
            // cout<<" left "<<left<<" extra "<<extra<<endl;
            if(left>extra)h=mid;
            else l=mid;
        }
        
        return l;
        
        
        
        
        
        
        
        //Dry RUn on these.
//             2
//             [11,3,22]
        
//         5
//         [1,6,7,8,9,15]
      /*  
        int runtime=0;
        for(int i=1;i<top.size();i++){
            int sub=(top[i]-top[i-1])*(i);   
            if(extra>=sub){
                extra-=sub;
                runtime=i;
            }   
            else break;
        }
        long long mn=top[runtime];
        mn+=extra/(runtime+1);
        return mn;
        */
    }
    
};