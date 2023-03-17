class Trie {
    Trie* children[26]={NULL};
    bool isEnd=false;
public:
    Trie() {
        for(int i=0;i<26;i++){
            this->children[i]=NULL;
        }
        this->isEnd=false;
    }
    
    void insert(string word) {
        Trie*curr=this;
        for(auto i:word){
            if(!curr->children[i-'a'])curr->children[i-'a']=new Trie();
            curr=curr->children[i-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string word,Trie *curr) {
        // if(word.size()==0)return curr->isEnd;
        bool ans=false;
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                for(char c='a';c<='z';c++){
                    if(curr->children[c-'a']!=NULL){
                        ans=ans|search(word.substr(i+1),curr->children[c-'a']);
                        if(ans)return ans;
                    }
                }
                return ans;
            }
            else if(!(curr->children[word[i]-'a']))return false;
            else curr=curr->children[word[i]-'a'];
        }
        return curr->isEnd;
    }
};

class WordDictionary {
    private:
    Trie *node;
public:
    WordDictionary() {
        node=new Trie();
    }
    
    void addWord(string word) {
        node->insert(word);
    }
    
    bool search(string word) {
        
        return node->search(word,node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */