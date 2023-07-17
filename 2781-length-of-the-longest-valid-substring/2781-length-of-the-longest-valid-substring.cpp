class Solution {
public:
    int longestValidSubstring(string word, vector<string>& frbdn) {
        //Thanks Mukul Rawat for explaining.
        //Otherwise it would've taken me a lot of time to do this problem on my own.
        //So basically the main observation is that the max size of any forbidden string is 10.
        //so we can use variable sized sliding window where we will check from right pointer to
        //left pointer whether any substring is present in set or not.
        //since the max invalid string can be of size 10 ,so we will check for a string of 10 length atmost.
        //will keep updating the answer.
        //since the traversal is from right to left we reversed all the forbidden strings as well
        // to save time on finding newer susbtring efficiently.
        
        int n=word.size();
        unordered_set<string> st;
        
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