struct DSU{
    vector<int> parent,size;
    DSU(int n){
        parent.resize(n+1,0);
        // iota(parent.begin(),parent.end(),0);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        size.resize(n+1,0);
    }
    int find_parent(int i){
           // while (parent[i] != i)
            // {
            //     parent[i] = parent[parent[i]]; // Skip one level
            //     i = parent[i]; // Move to the new level
            // }
            // return i;
        
        if(parent[i]==i)return i;
        return (parent[i]=find_parent(parent[i]));
    }
    
    void _union(int a,int b){
        
        int pa=find_parent(a);
        int pb=find_parent(b);
        
        if(pa==pb)return;
        
        if(size[pa]<size[pb])
            swap(pa,pb);
        
        // parent[pb]=parent[pa];
        parent[pb]=pa;
        size[pa]+=size[pb];
        
    }
};

class Solution {
public:
    
    int numSimilarGroups(vector<string>& strs) {
        unordered_set<string> st;
        unordered_map<string,int> mp;
        int cnt=1;
        for(int i=0;i<strs.size();i++){
            if(st.find(strs[i])==st.end()){
                st.insert({strs[i]});
                mp[strs[i]]=cnt++;
                // mp[strs[i]]=i+1;
            }
            // if(mp.find(strs[i])==mp.end())
        }
        
        int n=st.size();
        DSU d(n+1);
        // for(int i=0;i<=n;i++){
        //     cout<<d.parent[i]<<" ";
        // }
        // cout<<endl;
        auto it=st.begin();
        int sz=strs[0].length();
        /*
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                int diff=0;
                 for(int k=0;k<sz;k++){
                     if(strs[i][k]!=strs[j][k])diff++;
                 }
                // if(diff<=2)d._union(mp[strs[i]],mp[strs[j]]);
                if(diff<=2)d._union(i+1,j+1);
            }
        }
        */
        // /*
        while(it!=st.end()){
            // bool skip=false;
            string s=*it;
            for(int i=0;i<sz-1;i++){
                for(int j=i+1;j<sz;j++){
                    // string temp=s;
                    if(s[i]==s[j])continue;
                    swap(s[i],s[j]);
                    
                    auto f=st.find(s);
                    if(f!=st.end()){
                        
                        // cout<<*it<<" "<<s<<" "<<temp<<endl;
                        // cout<<mp[*it]<<" "<<mp[s]<<endl;
                        d._union(mp[*it],mp[s]);
                        // auto next=it;
                        // it++;
                        // st.erase(next);
                        // skip=true;
                    }
                    swap(s[i],s[j]);
                    // if(skip)break;
                }
                // if(skip)break;
            }
            // if(!skip)it++;
            it++;
        }
        // */
        // for(int i=0;i<=n;i++){
        //     cout<<d.parent[i]<<" ";
        // }
        // cout<<endl;
        for(int i=1;i<=n;i++){
            d.find_parent(i);
        }
        
        set<int> components;
        for(int i=1;i<=n;i++){
            components.insert(d.parent[i]);
        }
        return components.size();
    }
};