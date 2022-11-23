class Solution {
public:
    //Striver's graph series 
    int ladderLength(string beg, string end, vector<string>& words) {
        //set to store the words (for easy find & erase)
        unordered_set<string> st(words.begin(),words.end());
        //queue storing the word & shortest level at which it's generated/reached
        queue<pair<string,int>>q;
        //taking starting word to be at level 1
        q.push({beg,1});
        
        //BFS
        while(!q.empty()){
            
            pair<string,int> p=q.front();
            string curr=p.first;
            int level=p.second;
            q.pop();
            
            //erase the current word as it has already been visited.
            //need to remove so that other words don't visit it again.
            //since we need shortest path.
            st.erase(curr);
            //if current word is end then return it's shortest level
            if(curr==end)return level;
            
            //for each word try out all the different words that can be formed
            int n=curr.size();
            for(int i=0;i<n;i++){
                string temp=curr;
                char c='a';
                while(c<='z'){
                    temp[i]=c;
                    //if the new word is found in set means it has not been visited
                    //we will push it at next level into the queue
                    if(st.find(temp)!=st.end()){
                        q.push({temp,level+1});
                    }
                    c++;
                }
            }
        }
        //if q is empty & we couldn't reach the end word that means no answer exists.
        
        return 0;
    }
};