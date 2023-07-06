class Solution {
public:

    int largestRectangleArea(vector<int>& a) {
    int n=a.size();
    vector<int> nge(n,0),pge(n,0);
    stack<int> stk;
    //next smaller element
    for(int i=n-1;i>=0;--i){
        while(!stk.empty() && a[stk.top()]>=a[i])stk.pop();
        if(stk.empty())nge[i]=n;// n denotes invalid index.greater than range.
        else nge[i]=stk.top();
        stk.push(i);
    }
    
    while(!stk.empty())stk.pop();
        
    //previous smaller element
    for(int i=0;i<n;i++){
        while(!stk.empty() && a[stk.top()]>=a[i])stk.pop();
        if(stk.empty())pge[i]=-1;//invalid index
        else pge[i]=stk.top();
        stk.push(i);
    }
    int ans=0;
    //difference between nge & pge * length = area.
    for(int i=0;i<n;i++){
        
        // if(pge[i]==-1)pge[i]=-1;        
        // if(nge[i]==-1)nge[i]=n;    
        
        ans=max(ans,(nge[i]-(pge[i]+1))*a[i]);
    }
    return ans;
    }
};