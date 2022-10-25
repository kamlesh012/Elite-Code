class Solution {
public:

    int largestRectangleArea(vector<int>& a) {
      int n=a.size();
    vector<int> nge(n,0),pge(n,0);
    stack<int> stk;
    
    for(int i=n-1;i>=0;--i){
        while(!stk.empty() && a[stk.top()]>=a[i])stk.pop();
        if(stk.empty())nge[i]=-1;
        else nge[i]=stk.top();
        stk.push(i);
    }
    
    while(!stk.empty())stk.pop();
    
    for(int i=0;i<n;i++){
        while(!stk.empty() && a[stk.top()]>=a[i])stk.pop();
        if(stk.empty())pge[i]=-1;
        else pge[i]=stk.top();
        stk.push(i);
    }
    int ans=0;
    if(n==1)ans=a[0];
    else{
        
        for(int i=0;i<n;i++){
            // int left=i,right=i;
            int left=i,right=i;
            // if(pge[i]==-1)pge[i]=i;
            if(nge[i]==-1)nge[i]=n;
            // cout<<left<<" "<<right<< " "<<a[i]<<endl;
            ans=max(ans,(nge[i]-pge[i]-1)*a[i]);
        }
    }
    return ans;
    }
};