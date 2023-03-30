class Trie{
    
    private:
    Trie* links[2];
    
    public:
    void insert(int n){
        Trie *node=this;
        for(int i=30;i>=0;--i){
            int bit=0;
            if((1<<i)&n)bit++;
            if(!node->links[bit]){
                node->links[bit]=new Trie();
            }
            node=node->links[bit];
        }
    }
    
    int get_max(int x){
        int ans=0;
        Trie *node=this;
        for(int i=30;i>=0;--i){
            int bit=0;
            if((1<<i)&x)bit++;
            if(node->links[!bit]){
                ans=ans|(1<<i);
                node=node->links[!bit];
            }
            else node=node->links[bit];
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie *t=new Trie();
        for(auto i:nums){
            t->insert(i);
        }
        
        int ans=INT_MIN;
        for(auto i:nums){
            ans=max(ans,t->get_max(i));
        }
        return ans;
    }
};