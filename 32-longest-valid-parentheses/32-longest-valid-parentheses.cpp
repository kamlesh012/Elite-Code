class Solution {
public:
    //Learnt a new way to use stack.
    //Conceptual/Fundamental/Standard.
    int longestValidParentheses(string s) {
        stack<int> stk;
    //Bottom of stack will always store the index after which a longest valid parenthesis might be possible
        stk.push(-1);
        
        int mx=0;
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')stk.push(i);
            else {
                
                //pop the top first
                stk.pop();
                if(stk.empty()){
                     //dry run on this for clarity: ())()
                    
                    //explanation:
                           //if stk is empty after popping means we have removed the initially pushed -1 & implies we have an extra ')' & longest valid parenthesis is not possible.
                    //so we push index(i) to mark our index as new boundary
                //after which longest valid parenthesis might be possible
                    
                //the boundary initially was -1. now since we just poped -1 when we encountered an extra ')' so we are using it's index to mark the boundary index after which long valid parenthesis might be possible.
                //not using -1 as marker everytime instead using current index as it will help in calculating the length of longest possible valid parenthiesis by subtracting current index from the boundary.
                   
                    stk.push(i);
                }
                else{
                      //dry run on this ((())) for clarity
                    
                    //explanation:
                    //if stk is not empty that means at the top of the stack the leftmost index from which a longest valid parenthesis might start will be stored.so we will use that leftmost index to calculate the length of current valid parenthesis.(i-stk.top()) & compare it with mx
                    
                  
                    mx=max(mx,i-stk.top());
                }
            }
        }
        
        return mx;
    }
};