class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mat) {
        //largest area in a histogram
        //find next smaller element for each index & previous smaller element for each index
        //ans=max(ans,(nextsmaller-previoussmaller+1)*n) will be the answer.
        int n=mat.size(),m=mat[0].size();
        //now how is this problem related to Largest Area in a Histogram?
        //after some observation you can notice that each row can be considered
        //as base on which buidings of 1's is formed, this makes this problem exactly same to
        //largest area in a histogram
        
        stack<int> stk;
        function<int(vector <int>)> histogram=[&](vector<int> base){
            vector<int> prev(m,-1),next(m,m);
            // cout<<"Base in func :"<<endl;
            //  for(auto i:base){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            
            //finding next smaller element
            for(int i=m-1;i>=0;--i){
                while(stk.size() && base[stk.top()]>=base[i])stk.pop();
                if(stk.empty())next[i]=m;
                else next[i]=stk.top();
                stk.push(i);
            }
            while(stk.size())stk.pop();
            
            //finding prev smaller element
            for(int i=0;i<m;i++){
                while(stk.size() && base[stk.top()]>=base[i])stk.pop();
                if(!stk.size())prev[i]=-1;
                else prev[i]=stk.top();
                stk.push(i);
            }
            while(stk.size())stk.pop();
            
//             cout<<"Next :"<<endl;
//             for(auto i:next){
//                 cout<<i<<" ";
//             }
//             cout<<endl;
            
//             cout<<"Prev :"<<endl;
//             for(auto i:prev){
//                 cout<<i<<" ";
//             }
//             cout<<endl;
            
            int area=0;
            for(int i=0;i<m;i++){
                area=max(area,(next[i]-prev[i]-1)*base[i]);
            }
            // cout<<"AREA "<<area<<endl;
            return area;
        };
        
        vector<int> base(m,0);
        int ans=0;
        for(int row=0;row<n;row++){
            for(int i=0;i<m;i++){
                //rectanlge not possible since base cell is zero
                if(mat[row][i]=='0')base[i]=0;
                //else increase the height of reactangle by one.
                else base[i]+=1;
            }
            //Here in above Portion we are using already calculated heights 
            //from previous(above) row for current row. 
            //hence it's DP as well.
            
            // cout<<"Base :"<<endl;
            //  for(auto i:base){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            ans=max(ans,histogram(base));
            // cout<<"Ans :"<<ans<<endl;
        }
        return ans;
    }
};