class StockSpanner {
public:
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        //MOnotonice STack 
        //First part will store the element second part will store the no. of  elemnents that has been removed just before it(becuase they were smaller or equal to)
        
        int cnt=1;      //count itself
        while(stk.size() && price>=stk.top().first){
            cnt+=stk.top().second;  //add count of removed elements
            stk.pop();
        }
        stk.push({price,cnt});
        
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */