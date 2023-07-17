class Solution {
public:
    int longestValidSubstring(string word, vector<string>& frbdn) {
        int n=word.size();
        set<string> st;
        
        for(auto &i:frbdn){
            reverse(i.begin(),i.end());
            st.insert(i);
        }
        
        int mn=0,mnl=0,j=0;
        for(int i=0;i<n;i++){
            int k=i;
            string temp;
            while(k>=j && i-k<=9){
                temp.push_back(word[k]);
                if(st.find(temp)!=st.end()){
                    j=k+1;
                    break;
                }
                k--;
            }
            mnl=max(mnl,i-j+1);
        }
        return mnl;
    }
};