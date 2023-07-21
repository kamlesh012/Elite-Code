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
//head and tail are dummy nodes use to ease the implementation
node *head=new node(0,0);
node *tail=new node(0,0);

//Working:
//head->X->Y...->Z->tail
//New nodes are added after head.
//that means a node that is closer to head is more recent than the one that is closer to tail.
//to remove LRU node we will remove the least recent node that is just before tail.

//map stores key with node pointer. IT stores where in our linked list the node with the given key exists.
//storing the pointer to the key will save time required to traverse the list.
//this is the main concept. that takes this algorithm from O(n) to O(1).

//Base one Striver's Solution Using Self Created Doubly Linked List
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