class MedianFinder {
public:
    priority_queue<int> mxh;
    priority_queue<int,vector<int>,greater<int>> mnh;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //Insertion
        if(mnh.empty() || num>mnh.top())mnh.push(num);
        else mxh.push(num);
        
        //Balancing
        // cout<<mnh.size()<<" "<<mxh.size()<<endl;
        if(mnh.size()>mxh.size() && mnh.size()-mxh.size()>1){
            mxh.push(mnh.top());
            mnh.pop();
        }
        else if(mxh.size()>mnh.size() && mxh.size()-mnh.size()>1){
            mnh.push(mxh.top());
            mxh.pop();
        }
        // cout<<mnh.size()<<" "<<mxh.size()<<endl;
    }
    
    double findMedian() {
        if(mxh.size()==mnh.size()){
            return (mxh.top()+mnh.top())/2.0;
        }
        else if(mxh.size()>mnh.size())return (double)mxh.top();
        else return (double)mnh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */