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
        
        
        //MY Binary Search
        long long l=-1ll,h=total+1ll;
        while(h-l>1){
            long long mid=(h-l)/2+l;
            long long left=0ll;
            for(auto &i:top){
                left+=max(0ll,mid-i);
            }
            if(left>extra)h=mid;
            else l=mid;
        }
        
        return l;

     /* 
      //Greedy/Common Sense/Prefix Sum
      
        sort(top.begin(),top.end());
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
        
                //Dry RUn on these.
//             2
//             [11,3,22]
        
//         5
//         [1,6,7,8,9,15]
    }
    
};