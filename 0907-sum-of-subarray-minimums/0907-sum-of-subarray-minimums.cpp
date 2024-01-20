class Solution {
public:
    int n;
    int M = 1e9+7;
    void NextSmallestToRight(vector<int>& arr, vector<int>& NSR) {
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--) {
            if(st.empty()) {
                NSR[i] = n;
                st.push(i);
            } else {
                while(!st.empty() && arr[i] <= arr[st.top()]) {
                    st.pop();
                }
                
                NSR[i] = st.empty() ? n : st.top();
                st.push(i);
            }
        }
    }
    
    void NextSmallestToLeft(vector<int>& arr, vector<int>& NSL) {
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                NSL[i] = -1;
                st.push(i);
            } else {
                while(!st.empty() && arr[i] < arr[st.top()]) {
                    st.pop();
                }
                
                NSL[i] = st.empty() ? -1 : st.top();
                st.push(i);
            }
        }
    }
    
    int sumSubarrayMins(vector<int>& arr) {
        n = arr.size();
        vector<int> NSR(n);
        vector<int> NSL(n);
        
        NextSmallestToRight(arr, NSR);
        NextSmallestToLeft(arr, NSL);
        
        long result = 0;
        
        for(int i = 0; i < n; i++) {
            long nsl = (i - NSL[i]);
            long nsr = (NSR[i] - i);
            
            result = (result + (nsl*nsr)*arr[i]) % M;
        }
        
        
        return result;
    }
};