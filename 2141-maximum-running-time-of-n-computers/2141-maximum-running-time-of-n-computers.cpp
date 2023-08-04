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
        
//             2
//             [11,3,22]
        
//         5
//         [1,6,7,8,9,15]
        
        int runtime=0;
        for(int i=1;i<top.size();i++){
            int sub=(top[i]-top[i-1])*(i);
            cout<<"sub "<<sub<<" "<<extra<<endl;
            
            if(extra>=sub){
                extra-=sub;
                runtime=i;
            }   
            else break;
        }
        
        cout<<"TOP"<<endl;
        for(auto i:top){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<"EXTRA "<<extra<<endl;
        long long mn=top[runtime];
        cout<<runtime<<" runtime "<<top[runtime]<<endl;
        cout<<mn<<endl;
        mn+=extra/(runtime+1);
        return mn;
    }
    
};