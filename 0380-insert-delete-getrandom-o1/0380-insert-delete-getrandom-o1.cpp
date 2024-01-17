class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int, int> mp;
    
    RandomizedSet() {
        
    }

    bool insert(int val) {
      if(mp.find(val)!=mp.end())return false;
        
        mp[val]=v.size();
        v.push_back(val);
        return true;
    }
    
   
    bool remove(int val) {
     if(mp.find(val)==mp.end())return false;
        mp[v.back()]=mp[val];
        v[mp[val]]=v.back();
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
  
    int getRandom() {
        return v[rand()%v.size()];
    }
private:
   
};