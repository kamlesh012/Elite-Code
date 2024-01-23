class Solution {
public:
    int maxLength(vector<string>& arr,string str="",int index=0) {
        unordered_set<char> st(str.begin(),str.end());
        if(st.size()!=str.length())return 0;
        
        int curr=str.length();
        for(int i=index;i<arr.size();i++){
            curr=max(curr,maxLength(arr,str+arr[i],i+1));
        }
        return curr;
    }
};