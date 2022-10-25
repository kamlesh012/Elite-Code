class Solution {
public:

    int largestRectangleArea(vector<int>& a) {
        //a lot of doubts still
  int n=a.size();
    vector<int> nge(n,0),pge(n,0);
    stack<int> stk;
    //next smaller element
    for(int i=n-1;i>=0;--i){
        while(!stk.empty() && a[stk.top()]>=a[i])stk.pop();
        if(stk.empty())nge[i]=-1;
        else nge[i]=stk.top();
        stk.push(i);
    }
    
    while(!stk.empty())stk.pop();
    //previous smaller element
    for(int i=0;i<n;i++){
        while(!stk.empty() && a[stk.top()]>=a[i])stk.pop();
        if(stk.empty())pge[i]=-1;
        else pge[i]=stk.top();
        stk.push(i);
    }
    int ans=0;
    //difference between nge & pge * length = area.
    for(int i=0;i<n;i++){
        
        if(pge[i]==-1)pge[i]=-1;        //don't know how this is working
        if(nge[i]==-1)nge[i]=n;     //saw this is discss section.don't know why not same for pge.
        //working how? still to debug.
        
        // cout<<left<<" "<<right<< " "<<a[i]<<endl;
        ans=max(ans,(nge[i]-pge[i]-1)*a[i]);
    }
    return ans;
    }
};