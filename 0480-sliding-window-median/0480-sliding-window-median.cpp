class Solution {
public:
    struct comp{
        bool operator()(long long a,long long b)const{
            return a>b;
        }
    };
    
    vector<double> medianSlidingWindow(vector<int>& a, int k) {
        
        int n=a.size();
        multiset<long long> mnh;
        multiset<long long,comp> mxh;
        // for(auto i:a){
        //     mnh.insert(i);
        //     mxh.insert(i);
        // }
//         for(auto i:mnh){
//             cout<<i<<" ";
//         }
//         cout<<endl;
        
//         for(auto i:mxh){
//             cout<<i<<" ";
//         }
        cout<<endl;
        vector<double> ans;
        for(int i=0;i<n;i++){
            if(mnh.empty() || *mnh.begin()<a[i]){
                mnh.insert(a[i]);
            }
            else mxh.insert(a[i]);
            
            if(i>=k){
                auto it=mxh.find(a[i-k]);
                if(it!=mxh.end())mxh.erase(it);
                else {
                    mnh.erase(mnh.find(a[i-k]));
                }
            }
            
            if(mnh.size()>mxh.size() && mnh.size()-mxh.size()>1){
                mxh.insert(*mnh.begin());
                mnh.erase(mnh.begin());
            }
            else if(mnh.size()<mxh.size() && mxh.size()-mnh.size()>1){
                mnh.insert(*mxh.begin());
                mxh.erase(mxh.begin());
            }
            
            if(i>=k-1){
                if(mnh.size()==mxh.size()){
                    long long add=((*mnh.begin())+(*mxh.begin()));
                    double curr=add/2.0;
                    ans.push_back(curr);
                }
                else if(mnh.size()>=mxh.size()){
                    ans.push_back(*mnh.begin());
                }
                else ans.push_back(*mxh.begin());
            }
//             cout<<"Min Heap"<<endl;
//             for(auto j:mnh){
//             cout<<j<<" ";
//         }
//         cout<<endl;
            
//         cout<<"Max Heap"<<endl;
//         for(auto j:mxh){
//             cout<<j<<" ";
//         }
//                     cout<<endl;
        }
        return ans;
    }
};