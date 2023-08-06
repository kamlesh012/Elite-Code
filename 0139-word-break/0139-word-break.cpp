struct Node{
    Node* child[26]={NULL};
    bool isEnd=false;
};

Node* insert(Node * root,string s){
    if(!root)root=new Node();
    
    Node *curr=root;
    for(auto c:s){
        if(!curr->child[c-'a'])curr->child[c-'a']=new Node();
        curr=curr->child[c-'a'];
    }
    curr->isEnd=true;
    return root;
}

bool found(Node *root,string s){
    Node *dummy=root;
    for(auto i:s){
        if(dummy && dummy->child[i-'a'])dummy=dummy->child[i-'a'];
        else return false;
    }
    return dummy->isEnd;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        
        //Storing words in  Trie
        Node* root=NULL;
        for(auto i:wd){
            root=insert(root,i);
        }
        
        //Storing in Ump
        // unordered_map<string,int> mp;
        // for(auto i:wd){
        //     mp[i]++;
        // }
        
        int n=s.size();
        
        vector<bool> dp(n+1,0);
        dp[n]=true;
        for(int start=n-1;start>=0;--start){
            string temp;
            for(int end=start;end<n;end++){
                temp.push_back(s[end]);
                
                //Finding the given substring using Trie
                bool fnd=found(root,temp);
                
                //Using Unordered_Map
                // bool fnd=mp.count(temp);
                dp[start]=dp[start]|(fnd && dp[end+1]);
            }
        }
        return dp[0];
        
      // DP[i] represents whether the substring  starting at position is valid or not.
//         vector<int> dp(n,-1);
//         function<int(int)> rec=[&](int i){
//             if(i==n)return 1;
//             if(dp[i]==-1){
//                 dp[i]=0;
//                 string temp;
//               for(int j=0;j+i<n;j++){
//                   temp.push_back(s[i+j]);
//                   int found=mp.count(temp);
//                   dp[i]|=(found&rec(i+j+1));
//               }
//             }
//             return dp[i];
//         };
        
//         return rec(0);
    }
};