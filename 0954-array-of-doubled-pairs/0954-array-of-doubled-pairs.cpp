struct comp{
    bool operator()(const int &a,const int &b)const{
        return a>b;
    }
};
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        multiset<int> st;
        multiset<int,comp> mst;
        for(auto i:arr){
            if(i>0)st.insert(i);
            else mst.insert(i);
        }
        
        for(auto i:st){
            auto it=st.find(2*i);
            if(it!=st.end())st.erase(it);
            else return false;
            
            if(st.empty())break;
        }
        
        for(auto i:mst){
            auto it=mst.find(2*i);
            if(it!=mst.end())mst.erase(it);
            else return false;
            
            if(mst.empty())break;
        }
        return true;
    }
};