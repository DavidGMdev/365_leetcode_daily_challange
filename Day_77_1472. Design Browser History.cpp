class BrowserHistory {
public:
    stack<string> s1 , s2 , emp;
    BrowserHistory(string homepage) {
        s1.push(homepage);
    }

    void visit(string url) {
        s1.push(url);
        s2 = emp; 
    }
    
    string back(int steps) {
       while( steps-- && s1.size() > 1 ){
           s2.push(s1.top());
           s1.pop();
       }
       return s1.top();
    }
    
    string forward(int steps) {
        while( steps-- && s2.size() ){
           s1.push(s2.top());
           s2.pop();
       }
       return s1.top();
    }

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
