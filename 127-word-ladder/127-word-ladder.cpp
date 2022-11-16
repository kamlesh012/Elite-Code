class Solution {
public:
    int ladderLength(string beg, string end, vector<string>& words) {
        unordered_set<string> st;
        
        //inserting all into set for logn search & erase.
        for(auto i:words){if(i!=beg)st.insert(i);}
        
        int n=beg.length();
        
        //creating a queue for different valid string & its level of occurence
        queue<pair<string,int>> q;
        
        //insert the start string with level set to 1;
        q.push({beg,1});
            
        //applying bfs.
        while(!q.empty()){
            string s=q.front().first;
            int level=q.front().second;
            
            if(s==end)return level; //if given string is endWord then return it's level
            
            q.pop();
            st.erase(s);    //erasing the current string from set & queue to avoid cycle.
            
            //for each word check all possible words that can be formed by changing a letter.
            for(int i=0;i<s.length();i++){
                string temp=s;
                s[i]='a';
                while(s[i]<='z'){
                    //if the word formed by changing a letter is found in set
                    if(st.find(s)!=st.end()){
                        //push it to queue & increase it's level by 1.
                        q.push({s,level+1});
                    }
                    s[i]++;
                }
                s=temp;
            }
        }
        
        return 0;
    }
};