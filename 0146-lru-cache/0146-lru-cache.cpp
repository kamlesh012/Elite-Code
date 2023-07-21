//Custom Doubly Linked List Node CLass
class node{
    public:
    int val;
    int key;
    node* next;
    node *prev;
    node(int key,int val){
        this->key=key;
        this->val=val;
    }
};

//Global Head & Tail Pointers
node *head=new node(0,0);
node *tail=new node(0,0);

class LRUCache {
    int n;
    unordered_map<int,node*> mp;
public:
     LRUCache(int capacity) {
        n = capacity;   
         head->next=tail;
         tail->prev=head;
    }
    void add(node *newnode){
        newnode->next=head->next;
        head->next->prev=newnode;
        head->next=newnode;
        newnode->prev=head;
    }
    void del(node *newnode){
        newnode->prev->next=newnode->next;
        newnode->next->prev=newnode->prev;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        node *curr=mp[key];
        del(curr);
        add(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            if(mp.size()==n){
                mp.erase(tail->prev->key);
                del(tail->prev);
            }
            node *curr=new node(key,value);
            add(curr);
            mp[key]=curr;
        }
        else{
            node *curr=mp[key];
            curr->val=value;
            
            del(curr);
            add(curr);
        }
        
    }
};


































//Striver's Solution Using Self Created Doubly Linked List
/*
class LRUCache {
public:
class node
{
  public:
  int key;
  int val;
  node* next;
  node* prev;
  node(int _key,int _val)
  {
    key = _key;
    val = _val;
  }
};
node* head = new node(-1,-1);
node* tail = new node(-1,-1);

int size;
unordered_map<int,node*>mpp;
    LRUCache(int capacity) {
       size = capacity; 
       head->next = tail;
       tail->prev = head;  
    }

    void addNode(node* newNode){
       
       node* temp = head->next;
       newNode->next = temp;
       newNode->prev = head;
       head->next = newNode;
       temp->prev = newNode;
    }

    void deleteNode(node* delNode){
         
       node* delprev = delNode->prev;
       node* delnext = delNode->next;
       delprev->next = delnext;
       delnext->prev = delprev;
    }
    
    int get(int _key) {
        
        if(mpp.count(_key))
        {
          node* nde = mpp[_key];
          int curr = nde->val;
          mpp.erase(_key);
          deleteNode(nde);
          addNode(nde);
          mpp[_key] = head->next;
          return curr;
        }
        return -1;
    }
    
    void put(int _key, int value) {
        
        if(mpp.count(_key))
        {
           node* nde = mpp[_key];
           mpp.erase(_key);
           deleteNode(nde);
        }
        if(mpp.size()==size)
        {
           mpp.erase(tail->prev->key);
           deleteNode(tail->prev);
        }
        addNode(new node(_key,value));
        mpp[_key] = head->next;
    }
};
*/
//A concise solution using C++ STL
 /*

class LRUCache {
    int capacity;
    list<pair<int, int>> li;
    unordered_map<int, list<pair<int, int>>::iterator> um; 

public:
    LRUCache(int capacity) : capacity{capacity} {}
    
    int get(int key) {
        if (um.find(key) == um.end()) return -1;
        li.splice(li.begin(), li, um[key]);     //MOve node to begin/head
        return um[key]->second;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            um[key]->second = value;
            return;
        }
        
        if (um.size() == capacity) {
            int delKey = li.back().first;
            li.pop_back();
            um.erase(delKey);
        }
        
        li.emplace_front(key, value);
        um[key] = li.begin();
    }
};
 */