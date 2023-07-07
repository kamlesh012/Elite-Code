class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
     //Almost Same as Largest rectangle in a histogram.
        
    int n=a.size();
    vector<int> nse(n,0);       //stores next smaller elements
    vector<int> pse(n,0);   //stores previous smaller elements
        
    stack<int> stk;
        
    //finding next smaller elements for each element
    for(int i=n-1;i>=0;--i){
        while(!stk.empty() && a[stk.top()]>=a[i])stk.pop();
        if(stk.empty())nse[i]=n;// n denotes invalid index.greater than range.
        else nse[i]=stk.top();
        stk.push(i);
    }
    
    while(!stk.empty())stk.pop();
        
    //finding previous smaller elements for each element
    for(int i=0;i<n;i++){
        while(!stk.empty() && a[stk.top()]>=a[i])stk.pop();
        if(stk.empty())pse[i]=-1; //-1 denotes invalid index.smaller than range
        else pse[i]=stk.top();
        stk.push(i);
    }
        
    int ans=0;
    for(int i=0;i<n;i++){
        int left_boundary=pse[i];
        int right_boundary=nse[i];
        //here current element is the minimum in the segment(left_boundary,right_boundary)
        //here I am checking if the left_boundary is smaller than k & right_boundary is
        //greater than k.if these conditions satsify only then current element can be 
        //considered for answer.
        if(left_boundary<k && right_boundary>k)
        ans=max(ans,(nse[i]-pse[i]-1)*a[i]);
    }
        
    return ans;
    }
};