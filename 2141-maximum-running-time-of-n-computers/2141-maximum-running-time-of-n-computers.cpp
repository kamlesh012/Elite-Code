class Solution {
public:
    long long maxRunTime(int n, vector<int>& bat) {
        long long ans=0,extra=0;
        vector<int> top;
        sort(bat.rbegin(),bat.rend());
        for(int i=0;i<bat.size();i++){
            if(i<n)top.push_back(bat[i]);
            else extra+=bat[i];
        }
        sort(top.begin(),top.end());
        
        //Dry RUn on these.
//             2
//             [11,3,22]
        
//         5
//         [1,6,7,8,9,15]
        
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
    }
    
};