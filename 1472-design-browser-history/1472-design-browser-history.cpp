class BrowserHistory {
public:
    //Approach is using two stacks one for the pages that has been visited including current.
    //another stack for the pages that are to be visited in future.
    
    stack<string>backward,frwd;
    
    BrowserHistory(string homepage) {
        backward.push(homepage);
    }
    
    void visit(string url) {
        backward.push(url);
        
        frwd=stack<string>();   //resetting the future stack. stated in problem statement.
    }
    
    string back(int steps) {
        
        //backward contains the current url along with all previous
        //so size of backward stack must be at least 1.
        
        while(steps>0 && backward.size()>1){     
            //keep going back until either only current one page remains in history
            //or steps become zero
            
            frwd.push(backward.top());      //keep adding the pages to history for future visit.
            
            backward.pop();     //keep removing the current page as it has been added to future visit.
            
            steps--;
        }
        return backward.top();
    }
    
    string forward(int steps) {
        
        while(steps>0 && frwd.size()>0){
            backward.push(frwd.top());
            frwd.pop();
            steps--;
        }
        return backward.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */