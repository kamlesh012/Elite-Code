class Solution {
public:
    unordered_map<string,int> mp;
    vector<vector<string>> ans;
    string beginword;
    
    void dfs(string s,vector<string> &words){
        if(s==beginword){
            reverse(words.begin(),words.end());
            ans.push_back(words);
            reverse(words.begin(),words.end());
            return;
        }
        
        string temp=s;
        int steps=mp[temp];
        int sz=s.length();
        
        for(int i=0;i<sz;i++){
            s[i]='a';
            while(s[i]<='z'){
                if(mp.find(s)!=mp.end() && mp[s]+1==steps){
                    words.push_back(s);
                    dfs(s,words);
                    words.pop_back();
                }
                s[i]++;
            }
            s=temp;
        }
        
    }
    
    vector<vector<string>> findLadders(string beg, string end, vector<string>& words) {
        //first use code of Word Ladder 1 to find the minimum step at which each word occurs
        //store that minimum step in map
        
        unordered_set<string> st(words.begin(),words.end());
        queue<string> q;
        q.push(beg);
        mp[beg]=1;    
        st.erase(beg);
        
        
        
        while(!q.empty()){
            
            string curr=q.front();
            int level=mp[curr];
            q.pop();
            
        //storing minimum step of curr in map  only if not already stored.
            // if(mp[curr]==0)mp[curr]=level;
            // else if(mp[curr]<level && curr==end)break;
            
            if(curr==end)break;     //if end word found break;
            
            for(int i=0;i<curr.length();i++){
                string temp=curr;
                char c='a';
                while(c<='z'){
                    temp[i]=c;
                    if(st.find(temp)!=st.end()){
                        q.push(temp);
                        st.erase(temp);
                        mp[temp]=level+1;
                    }
                    c++;
                }
            }
        }
        
        // for(auto i:mp){
        // cout<<i.first<<" "<<i.second<<endl;
        //     }
        //after finding the minimum step of each word from start to begin in minimum path
        //we traverse from end to begin trying only those possibilites that exist
        //in our map at lower leve/previous step to save time
        
        
        beginword=beg;      //setting global beginword to beg. condition to stop dfs.
        
        if(mp.find(end)!=mp.end()){
            vector<string> sequence{end};
            dfs(end,sequence);       //start dfs from last word till we reach first
            
        }
        
        //since our answer is from end to begin we reverse every possible answer vector.
        // for(auto &i:ans){
        //     reverse(i.begin(),i.end());
        // }
        
        return ans;
        
    }
};