//Striver's Solution Using Self Created Doubly Linked List
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

//A concise solution using C++ STL
/*
class LRUCache{
    size_t m_capacity;
    unordered_map<int,  list<pair<int, int>>::iterator> m_map; //m_map_iter->first: key, m_map_iter->second: list iterator;
    list<pair<int, int>> m_list;                               //m_list_iter->first: key, m_list_iter->second: value;
public:
    LRUCache(size_t capacity):m_capacity(capacity) {
    }
    int get(int key) {
        auto found_iter = m_map.find(key);
        if (found_iter == m_map.end()) //key doesn't exist
            return -1;
        m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
        return found_iter->second->second;                         //return value of the node
    }
    void set(int key, int value) {
        auto found_iter = m_map.find(key);
        if (found_iter != m_map.end()) //key exists
        {
            m_list.splice(m_list.begin(), m_list, found_iter->second); //move the node corresponding to key to front
            found_iter->second->second = value;                        //update value of the node
            return;
        }
        if (m_map.size() == m_capacity) //reached capacity
        {
           int key_to_del = m_list.back().first; 
           m_list.pop_back();            //remove node in list;
           m_map.erase(key_to_del);      //remove key in map
        }
        m_list.emplace_front(key, value);  //create new node in list
        m_map[key] = m_list.begin();       //create correspondence between key and node
    }
};

*/