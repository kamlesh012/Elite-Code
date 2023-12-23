class LockingTree {
public:
    
    int nodes;
    vector<int> p;
    unordered_map<int,int> lockedby;
    vector<set<int>>locked_children;
    
    LockingTree(vector<int>& parent) {
        nodes=parent.size();
        p=parent;
        locked_children.resize(nodes);
    }
    
    bool lock(int num, int user) {
        if(lockedby.find(num)==lockedby.end()){
            
            int par=p[num];
            int child=num;
            while(par!=-1){
                locked_children[par].insert(num);
                child=par;
                par=p[par];
            }
            lockedby[num]=user;
            return true;
        }
        else return false;
    }
    
    bool unlock(int num, int user){
        if(lockedby.find(num)!=lockedby.end() && lockedby[num]==user){
            //erase from all ancestors
            int par=p[num];
            int child=num;
            while(par!=-1){
                locked_children[par].erase(locked_children[par].find(num));
                child=par;
                par=p[par];
            }
            lockedby.erase(lockedby.find(num));
            return true;
        }
        else return false;
    }
    
    bool upgrade(int num, int user) {
        if(lockedby.find(num)==lockedby.end()){
            int par=p[num];
            int child=num;
            while(par!=-1){
                if(lockedby.find(par)!=lockedby.end())return false;
                child=par;
                par=p[par];
            }
            if(locked_children[num].size()){
                for(auto i:locked_children[num]){
                    int id=lockedby[i];
                    unlock(i,id);
                }
                
               return lock(num,user);
                
            }
            else return false;
        }
        else return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */