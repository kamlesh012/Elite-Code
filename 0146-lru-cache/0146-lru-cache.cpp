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
// /*

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

// */