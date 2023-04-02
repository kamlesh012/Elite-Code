struct Node{
    Node *links[2]={NULL};
};

class Trie{
    private:
    Node *root;
    public:
    Trie(){
        root=new Node();
    }
    
    void insert(int n){
        Node *dummy=root;
        for(int i=31;i>=0;--i){
            int bit=((1<<i)&n)?1:0;
            if(!dummy->links[bit]){
                dummy->links[bit]=new Node();
            }
            dummy=dummy->links[bit];
        }
    }
    
    long long get_max(int n){
        long long ans=0ll;
        Node *dummy=root;
        
        for(int i=31;i>=0;--i){
            int bit=((1<<i)&n)?1:0;
            if(!dummy)return -1;
            
            if(dummy->links[1-bit]){
                ans=ans|(1ll<<i);
                dummy=dummy->links[1-bit];
            }
            else dummy=dummy->links[bit];
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        multimap<vector<int>,int> mpq;
        for(int i=0;i<queries.size();i++){
            // mpq[queries[i]]=i;
            mpq.insert({queries[i],i});
        }
        sort(queries.begin(),queries.end(),[&](vector<int> a,vector<int>b){
            if(a[1]==b[1])return a[0]<b[0];
            return a[1]<b[1];
        });
        int j=0,n=nums.size();
        sort(nums.begin(),nums.end());
        Trie *t=new Trie();
        vector<int> ans(queries.size(),0);
        for(auto i:queries){
            while(j<n && nums[j]<=i[1]){
                t->insert(nums[j]);
                j++;
            }
            // cout<<"Ans till this max "<<i[0]<<" "<<i[1]<<endl;
            long long mx=t->get_max(i[0]);
            // ans[mpq[i]]=mx;
            int index=mpq.find(i)->second;
            mpq.erase(mpq.find(i));
            ans[index]=mx;
            // cout<<i[0]<<" "<<i[1]<<" "<<ans[mpq[i]]<<endl;
        }
        return ans;
    }
};