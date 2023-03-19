struct Node{
    Node* links[26]={NULL};
    bool flag = false;
    bool containKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node* node)
    {
        links[ch -'a'] = node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root= new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(int i = 0;i<word.size();i++)
        {
            if(!(node->containKey(word[i])))
            {
                node->links[word[i]-'a']=new Node();
                // node->put(word[i],new Node());
            }
            node= node->get(word[i]);
        }
        node->setEnd();
    }

     bool searchHelper(string word, Node* node){
        for(int i=0; i<word.size(); i++){
            if(word[i] == '.'){
                for(char c='a';c<='z';c++){
                    if(node->containKey(c)){
                        if(searchHelper(word.substr(i+1), node->get(c)))
                            return true;
                    }
                }
                return false;
            }
            else if(!node->containKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        return searchHelper(word,node);
    }
};
/*
class Trie {
    Trie* children[26]={NULL};
    bool isEnd=false;
public:
    Trie() {
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
        for(int i=0;i<word.size();i++){
            if(word[i]=='.'){
                for(char c='a';c<='z';c++){
                    if(curr->children[c-'a']!=NULL){
                        if(search(word.substr(i+1),curr->children[c-'a']))
                            return true;
                    }
                }
                return false;
            }
            else if(!(curr->children[word[i]-'a']))return false;
            curr=curr->children[word[i]-'a'];
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
*/

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
