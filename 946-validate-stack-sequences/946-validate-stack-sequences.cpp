class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n=pushed.size(),j=0;
        for(int i=0;i<n;i++){
            while(j<n && stk.size() && popped[j]==stk.top()){
                j++;
                stk.pop();
                }
            stk.push(pushed[i]);
        }
        while(j<n && stk.size() && popped[j]==stk.top()){
                j++;
                stk.pop();
        }
        return stk.empty();
    }
};