// ##################################################
// solution 2.1 : more simple code for LL solution
// ##################################################

class BrowserHistory {
public:
    class Node {
        public : 
            string url ;
            Node *prev , *nxt ; 
            Node(){
                this->prev = NULL ; 
                this->url  = ""  ;
                this->nxt  = NULL  ; 
            }
            Node( Node* prev , string url , Node* nxt ){
                this->prev = prev ; 
                this->url  = url  ;
                this->nxt  = nxt  ; 
            }
    };
    Node *head , *curr ;
    BrowserHistory(string homepage) {
        head = new Node(NULL,homepage,NULL);
        curr = head ; // iterate on Linked list using it  
    }
    void visit(string url) {
        curr->nxt = new Node(curr,url,NULL);
        curr = curr->nxt; // move to visit it 
    }
    string back(int steps) {
       while( steps-- && curr->prev != NULL ) curr = curr->prev ;
       return curr->url; // worst case is homepage 
    }
    
    string forward(int steps) {
       while( steps-- && curr->nxt != NULL ) curr = curr->nxt ; 
       return curr->url; // worst case is latest pushed/visted page 
    }
};


// ##################################################
// solution 2 : using DLL ( Doubly linked list )
// ##################################################

class BrowserHistory {
public:
    class Node {
        public : 
            string url = "" ;
            Node* prev = NULL ;
            Node* nxt  = NULL ; 
            Node( string x ){
                this->url = x; 
            }
    };

    class DLL {
        public : 
            Node* head = NULL ;
            Node* curr = NULL ; 
            Node* tail = NULL ; // btw it's useless xD
    };

    DLL* hist = NULL ; // represents the history of browser object 
    
    BrowserHistory(string homepage) {
        hist = new DLL();
        hist->head = new Node(homepage);
        hist->tail = hist->curr = hist->head;
    }

    void visit(string url) {
        hist->curr->nxt = new Node(url);
        hist->curr->nxt->prev = hist->curr;
        hist->curr->nxt->nxt = NULL ;
        hist->curr = hist->curr->nxt;
    }
    
    string back(int steps) {
       while( steps-- && hist->curr->prev != NULL ) {
           hist->curr = hist->curr->prev ;
       }
       return hist->curr->url;
    }
    
    string forward(int steps) {
       while( steps-- && hist->curr->nxt != NULL ) {
            hist->curr = hist->curr->nxt ;
       }
       return hist->curr->url;
    }

};

// ##################################################
// solution 1 : using Stack
// ##################################################

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
