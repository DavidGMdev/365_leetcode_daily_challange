/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* vis[100+1];
    Node* dfs( Node* curr ){
        if( curr == NULL ) return NULL ; 
        if( vis[curr->val] != NULL ) return vis[curr->val] ;
        Node* nw = new Node(curr->val);
        vis[curr->val] = nw ; // dummy assignment to avoid cyclic behaviour due to post-call assignment ( at end of call )
        for( auto i : curr-> neighbors ){
            Node* child = dfs(i);
            nw->neighbors.push_back(child);
        }
        return vis[curr->val] = nw ; // final assignment with full copied Node info
    }
    Node* cloneGraph(Node* node) {
        for( int i = 0 ;  i < 101 ; i++ ) vis[i] = NULL ; 
        return dfs(node);
    }
};
